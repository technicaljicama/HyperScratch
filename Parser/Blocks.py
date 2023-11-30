from dataclasses import dataclass


@dataclass
class BasicBlock:
    next: str
    parent: str
    shadow: bool
    code: str

@dataclass
class EventBlock(BasicBlock):
    topLevel: bool
    
    
_known_blocks = {
    "event_whenflagclicked": EventBlock("a", "b", False, "", True),
    
}
