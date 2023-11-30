from dataclasses import dataclass

@dataclass
class Costume:
    name: str
    filename: str
    extension: str
    centerX: int = 0
    centerY: int = 0
    spriteIndex: int = 0
