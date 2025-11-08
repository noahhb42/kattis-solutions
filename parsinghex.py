import re
print('\n'.join(f'{s} {int(s,16)}' for s in re.findall('(?i)0x[0-9a-f]+',open(0).read())))