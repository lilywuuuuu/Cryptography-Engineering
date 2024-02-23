cipher = """T ZJDMBYFS VZRFGYRVY  DBVY JIYFG
FKMFSRFGZF T IFFARGL JI GJY
ITS SFDJEFC ISJD TATSD JG
TGTANQRGL TGC FKMAJSF
YOF IAJJC JI TCETGZFC XGJHAFCLF HORZO
FTZO NFTS WSRGLV HRYO RY """

freq = [0] * 26

for ch in range(len(cipher)):
    if cipher[ch] != " " and cipher[ch] != "\n":
        freq[ord(cipher[ch]) - ord("A")] += 1
print(freq)
