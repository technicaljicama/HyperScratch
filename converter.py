import json
import sys
import names
import random
from cairosvg import svg2png

"""
TODO:
Arg ("inputs") parser
Parse variables, broadcasts
C code writer
Resource (images and sound) parser
svg to png converter
"""

#480x360 res

#[What object?, What opcode?, Next opcode, This name, args, shadow(hidden)]
gBlocks = []

#[name, filename, centerX, centerY, sprite_index]
gCostumes = []

#[name, x, y, current, costume_name, layer]
gSprites = []

#[name, md5name]
gStages = []

gCode = """
#include "sprite.h"
#include "costume.h"\n
#include "blocks.h"\n
#include "stage.h"\n
inline int gWhileLoop = -1;\n
"""

gBroadcasts = []
gVariables = []

#[event name, junk name]
gEventBlocks = []

#
gControlBlocks = []

gFixedBlocks = ""
gTarget = -1

def convert_svg(name):
    if "svg" in name:
        f = open(name, "rb")
        
        svg2png(bytestring=f.read(), write_to=name[:-4]+".png")
        
        f.close()

def write_sprites():
    global gCode

    gCode += """#define MAX_SPRITES """+str(len(gSprites))+"""\ninline Sprite sprites["""+str(len(gSprites))+"""] = {\n"""
    for sprite in gSprites:
        gCode += """\t{\""""+sprite[0]+"""\", """+str(sprite[1])+""", """+str(sprite[2])+""", """+str(sprite[3])+""", \""""+sprite[4][:-4]+".png"+"""\", """+str(sprite[5])+"""},\n"""
        
    gCode += """};\n"""

def write_stages():
    global gCode

    gCode += """#define MAX_STAGES """+str(len(gStages))+"""\ninline Stage stages["""+str(len(gStages))+"""] = {\n"""
    for stage in gStages:
        gCode += """\t{\""""+stage[0]+"""\", \""""+stage[1][:-4]+".png"+"""\"},\n"""
        
    gCode += """};\n"""
    # print(gCode)

def parse_sline(block, iterator):
    global gCode
    
    if block[4] != {}:
        gCode += """\t"""+block[1]+"""("""+parse_argument(block, gBlocks[iterator + 1])+""", _sprite);\n"""
    else:
        gCode += """\t"""+block[1]+"""(_sprite);\n"""

def parse_argument(block, next_block):
    #Will improve this later... (I hope)
    global gCode
    
    args = block[4]
    match block[1]:
        case "looks_switchcostumeto":
            if next_block[1] == "looks_costume" and next_block[3] == args["COSTUME"][1]:
                return "\""+next_block[4]["COSTUME"][0]+"\""
        case "motion_goto":
            if next_block[1] == "motion_goto_menu" and next_block[3] == args["TO"][1]:
                return "\""+next_block[4]["TO"][0]+"\""
            
        case "control_forever":
            iterator = -1
            to_find = next_block[4]["SUBSTACK"][1]
            for block in gBlocks:
                iterator += 1
                if block[3] == to_find:
                    parse_sline(block, iterator)
            

def write_blocks():
    global gCode
    global gEventBlocks
    global gControlBlocks
    prev_owner = 1 #(stage is 0)
    #Problem: Stage has no code and starts at 0
    #Sprite has index 1
    #maybe an index for all sprites/stages?
    iterator = -1
    has_block = False
    for block in gBlocks:
        iterator += 1
        if block[5] != True:
            # if block[0] != prev_owner:
                # gCode += """//"""
                
            if block[1].startswith("event_"):
                if has_block:
                    gCode += """};\n"""
                has_block = False
                gCode += """inline void """+block[1]+block[3]+"""(Sprite &_sprite) {\n""" #TODO: Implement argument parser for events
                gEventBlocks.append([block[1], block[3]])
            elif block[1] == "control_forever":
                gCode += """\tgWhileLoop++;\n"""
                gCode += """};\n"""
                gCode += """inline void """+block[1]+block[3]+"""(Sprite &_sprite) {\n"""
                gControlBlocks.append([block[1], block[3]])
                parse_argument(block, block)
            else:
                has_block = True
                parse_sline(block, iterator)
                
            prev_owner = block[0]
                    
    gCode += """};\n"""

def write_block_lists():
    global gCode
    # global gEventBlocks
    sprite_clicked = []
    green_flag = []
    
    #Will be changed to be done by one function for both problems (See line 83)
        
    for ev_block in gEventBlocks:
        match ev_block[0]:
            case "event_whenthisspriteclicked":
                sprite_clicked.append(ev_block[0]+ev_block[1])
            case "event_whenflagclicked":
                green_flag.append(ev_block[0]+ev_block[1])
                
    # for ev_block in gControlBlocks:
        
    gCode += """\n#define MAX_WHILES """+str(len(gControlBlocks))
    gCode += """\ninline void(*_whileLoops["""+str(len(gControlBlocks))+"""])(Sprite &_sprite) {\n"""
    for event in gControlBlocks:
        gCode += """\t&"""+event[0]+event[1]+""",\n"""
    gCode += """};\n"""
    
    gCode += """\ninline void(*_spriteClicked["""+str(len(sprite_clicked))+"""])(Sprite &_sprite) {\n"""
    for event in sprite_clicked:
        gCode += """\t&"""+event+""",\n"""
    gCode += """};\n"""
    
    gCode += """\ninline void(*_greenFlagClicked["""+str(len(green_flag))+"""])(Sprite &_sprite) {\n"""
    for event in green_flag:
        gCode += """\t&"""+event+""",\n"""
    gCode += """};\n"""

def write_costumes():
    global gCode

    gCode += """#define MAX_COSTUMES """+str(len(gCostumes))+"""\ninline Costume costumes["""+str(len(gCostumes))+"""] = {\n"""
    for costume in gCostumes:
        gCode += """\t{\""""+costume[0]+"""\", \""""+str(costume[1][:-4])+".png\", """+str(costume[4])+""", 0 , 0, """+str(int(costume[2]))+""", """+str(int(costume[3]))+"""},\n"""
        
    gCode += """};\n"""
        
    # print(gCode)

def export_code(filename):
    f = open(filename, "w")
    f.write(gCode)
    f.close()

def parse_blocks(array, name):
    if array["shadow"] == True:
        gBlocks.append([gTarget, array["opcode"], array["next"], name, array["fields"], True])
    else:
        gBlocks.append([gTarget, array["opcode"], array["next"], name, array["inputs"], False])

def rename_blocks(blocks):
    global gBlocks
    bnames = []
    #done_names = []
    #parent_names = []
    parsed = -1
    
    for block in blocks:
        parsed += 1
        bnames.append([parsed, block[0], block[3]])
    
    for name in bnames:
        new_name = "block_"+str(name[0])+names.get_first_name().lower()+str(random.randint(0, 10))
        
        print("Block: "+new_name)
        
        gFixedBlocks = json.dumps(gBlocks).replace(name[2], new_name)
        gBlocks = json.loads(gFixedBlocks)

def parse_costumes(costumes, sprite_index):
    gCostumes.append([costumes["name"], costumes["md5ext"], costumes["rotationCenterX"], costumes["rotationCenterY"], sprite_index])

def parse_sprite(sprite, costume, currentCostume):
    gSprites.append([sprite["name"], int(240+sprite["x"]-costume["rotationCenterX"]), int(180-(sprite["y"]+costume["rotationCenterY"])), sprite["currentCostume"]+currentCostume, costume["md5ext"], sprite["layerOrder"]])

def parse_stage(costume):
    gStages.append([costume["name"], costume["assetId"]+"."+costume["dataFormat"]])

if __name__ == "__main__":
    spriteidx = -1
    stageidx = -1
    currentCostume = -1
    try:
        # .read()
        jo = json.load(open("project.json", "r"))
    except Exception as ex:
        print("Could not read project ("+str(ex)+")")
        sys.exit(-1)
    
    
    for objects in jo["targets"]:
        gTarget += 1
        # print(objects["blocks"][0])
        
        print(f"Parsing blocks in target {gTarget}...")
        for blocks in objects["blocks"]:
            parse_blocks(objects["blocks"][blocks], blocks)
            
        print(f"Parsing costumes in target {gTarget}...")
        if objects["isStage"] == False:
            spriteidx += 1
            for costume in objects["costumes"]:
                currentCostume += 1
                parse_costumes(costume, spriteidx)
                
            parse_sprite(objects, costume, currentCostume)
        elif objects["isStage"] == True:
            print("Parse stage...")
            stageidx += 1
            for costume in objects["costumes"]:
                # currentCostume += 1
                print(costume)
                parse_stage(costume)
                
            # parse_sprite(objects, costume, currentCostume)
    
    print("Renaming blocks...")
    rename_blocks(gBlocks)
    
    # print("Parsing costumes...")
    # parse_costumes()
    print(gBlocks)
    print("Converting svgs...")
    for svg in gCostumes:
        convert_svg(svg[1])
        
    print("Writing sprite code...")
    write_sprites()
    write_costumes()
    write_stages()
    
    print("Converting blocks to c++...")
    write_blocks()
    write_block_lists()
    #print(gCode)
    
    export_code("project.h")
