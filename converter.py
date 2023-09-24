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

#[What object?, What opcode?, Next opcode, This name, args]
gBlocks = []

#[name, filename, centerX, centerY]
gCostumes = []

#[name, x, y, current, costume_name, layer]
gSprites = []

gCode = """
#include "sprite.h"\n
"""

gBroadcasts = []
gVariables = []

gFixedBlocks = ""
gTarget = -1

def convert_svg(name):
    f = open(name, "rb")
    
    svg2png(bytestring=f.read(), write_to=name[:-4]+".png")
    
    f.close()

def write_sprites():
    global gCode

    gCode += """#define MAX_SPRITES """+str(len(gSprites))+"""\ninline Sprite sprites["""+str(len(gSprites))+"""] = {\n"""
    for sprite in gSprites:
        gCode += """\t{\""""+sprite[0]+"""\", """+str(sprite[1])+""", """+str(sprite[2])+""", """+str(sprite[3])+""", \""""+sprite[4][:-4]+".png"+"""\", """+str(sprite[5])+""" ,0 ,0},\n"""
        
    gCode += """};\n"""
        
    # print(gCode)

def export_code(filename):
    f = open(filename, "w")
    f.write(gCode)
    f.close()

def parse_blocks(array, name):
    if array["shadow"] == True:
        gBlocks.append([gTarget, array["opcode"], array["next"], name, array["fields"]])
    else:
        gBlocks.append([gTarget, array["opcode"], array["next"], name, array["inputs"]])

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

def parse_costumes(costumes):
    gCostumes.append([costumes["name"], costumes["md5ext"], costumes["rotationCenterX"], costumes["rotationCenterY"]])

def parse_sprite(sprite, costume):
    gSprites.append([sprite["name"], int(240+sprite["x"]-costume["rotationCenterX"]), int(180-(sprite["y"]+costume["rotationCenterY"])), sprite["currentCostume"], costume["md5ext"], sprite["layerOrder"]])

if __name__ == "__main__":
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
            for costume in objects["costumes"]:
                parse_costumes(costume)
                
                parse_sprite(objects, costume)
        else:
            print("Parse stage...")
    
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
    
    # print(gCode)
    
    export_code("project.h")
