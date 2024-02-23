dawn = "attack at dawn"
dusk = "attack at dusk"
int_string = int(dawn.encode().hex(), 16)
key = int_string ^ 0x09e1c5f70a65ac519458e7e53f36
int_problem = int(dusk.encode().hex(), 16)
ans = hex(int_problem ^ key)
print(ans)
