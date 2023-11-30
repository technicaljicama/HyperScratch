from dataclasses import dataclass
import Costume


@dataclass
class Sprite:
    name: str
    costumes: Costume 
    x: int = 0
    y: int = 0
    defaultCostume: int = 0
    layer: int = 0
    

