import json
import sys
import names
import random
import Sprite
import Costume
import Stage
import Blocks
from cairosvg import svg2png

class ScratchParser:
    def __init__(self, path = "project.json"):
        try:
            self.project = json.load(open(path, "r"))
        except Exception as ex:
            print("Could not read project ("+str(ex)+")")
            sys.exit(-1)
        
        #"name" contains the actual name of the specifc costume
        #"x" contains the actual x coordinate of the sprite in the window (center adjusted)
        #"y" contains the actual y coordinate of the sprite in the window (center adjusted)
        #"defaultCostume" contains index of the initial costume
        #"layer" contains the drawing layer of the sprite (e.g. 0 first, 10 last)
        #"costumes" contains all costumes needed for this sprite
        self.parsedSprites = []
        
        #"name" contains the actual name of the specifc costume
        #"filename" contains the name of the image (with extension)
        #"centerX" contains the x center (starting at x 0)
        #"centerY" contains the y center (starting at y 0)
        #"spriteIndex" contains the associated sprite index (one sprite can have multiple costumes).
        #"extension" contains the original image file extension (for svg conversion)
        self.parsedCostumes = []
        
        #"name" contains the actual name of the specifc costume
        #"filename" contains the name of the image (with extension)
        self.parsedStages = []
    
    #Maybe I could "merge" those two functions into one and save some time there ~ Done
    def parseSprites(self):
        temp_costumes = [] #basically the same as parsedCostumes, but temporary for each sprite
        spriteidx = -1
        for target in self.project["targets"]: #Go through all objects
            if target["isStage"] == False:
                temp_costumes = [] #Reset it
                spriteidx += 1 #Count the sprite that was associated with it
                for costume in target["costumes"]:
                    temp_costumes.append(Costume.Costume(costume["name"],
                                            costume["assetId"] + ".png", 
                                            costume["dataFormat"],
                                            costume["rotationCenterX"], 
                                            costume["rotationCenterY"], 
                                            spriteidx))
                    
                    self.parsedCostumes.append(temp_costumes[-1])
                    
                self.parsedSprites.append(Sprite.Sprite(
                                            target["name"],
                                            temp_costumes,
                                            int(240+target["x"]-temp_costumes[target["currentCostume"]].centerX), #Calculate "real" x coordinate (I just noticed godot already does this)
                                            int(180-(target["y"]+temp_costumes[target["currentCostume"]].centerY)), #Calculate "real" y coordinate 
                                            target["currentCostume"], 
                                            target["layerOrder"]))
                
    def parseStages(self):
        for target in self.project["targets"]: #Go through all objects
            if target["isStage"] == True:
                for stage in target["costumes"]:
                    self.parsedStages.append(Stage.Stage(stage["name"],
                                                stage["assetId"] + ".png"))
        
    #Converts all svg images in the project to pngs using cariosvg
    def convertSprites(self):
        for costume in self.parsedCostumes:
            if costume["extension"] == "svg":
                f = open(costume["filename"][:-4]+".svg", "rb")
                
                svg2png(bytestring=f.read(), write_to=costume["filename"])
                f.close()
    
if __name__ == "__main__":
    parser = ScratchParser()
    # parser.parseCostumes()
    parser.parseSprites()
    parser.parseStages()
    # print(parser.parsedStages)
