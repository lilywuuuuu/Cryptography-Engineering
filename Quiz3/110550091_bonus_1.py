import hashlib
hash1 = '5f4dcc3b5aa765d61d8327deb882cf99'
hash2 = '5a105e8b9d40e1329780d62ea2265d8a'
hash_list = [hash1, hash2]
passlist = ['12345', '123456', '123456789', 'test1', 'password', '12345678', 'zinch', 'g_czechout', 'asdf', 'qwerty', '1234567890', '1234567', 'Aa123456.', 'iloveyou', '1234', 'abc123', '111111', '123123', 'dubsmash', 'test', 'princess', 'qwertyuiop', 'sunshine', 'BvtTest123', '11111', 'ashley', '00000', '000000', 'password1', 'monkey', 'livetest', '55555', 'soccer', 'charlie', 'asdfghjkl', '654321', 'family', 'michael', '123321', 'football', 'baseball', 'q1w2e3r4t5y6', 'nicole', 'jessica', 'purple', 'shadow', 'hannah', 'chocolate', 'michelle', 'daniel', 'maggie', 'qwerty123', 'hello', '112233', 'jordan', 'tigger', '666666', '987654321', 'superman', '12345678910', 'summer', '1q2w3e4r5t', 'fitness', 'bailey', 'zxcvbnm', 'fuckyou', '121212', 'buster', 'butterfly', 'dragon', 'jennifer', 'amanda', 'justin', 'cookie', 'basketball', 'shopping', 'pepper', 'joshua', 'hunter', 'ginger', 'matthew', 'abcd1234', 'taylor', 'samantha', 'whatever', 'andrew', '1qaz2wsx3edc', 'thomas', 'jasmine', 'animoto', 'madison', '987654321', '54321', 'flower', 'Password', 'maria', 'babygirl', 'lovely', 'sophie', 'Chegg123', 'computer', 'qwe123', 'anthony', '1q2w3e4r', 'peanut', 'bubbles', 'asdasd', 'qwert', '1qaz2wsx', 'pakistan', '123qwe', 'liverpool', 'elizabeth', 'harley', 'chelsea', 'familia', 'yellow', 'william', 'george', '7777777', 'loveme', '123abc', 'letmein', 'oliver', 'batman', 'cheese', 'banana', 'testing', 'secret', 'angel', 'friends', 'jackson', 'aaaaaa', 'softball', 'chicken', 'lauren', 'andrea', 'welcome', 'asdfgh', 'robert', 'orange', 'Testing1', 'pokemon', '555555', 'melissa', 'morgan', '123123123', 'qazwsx', 'diamond', 'brandon', 'jesus', 'mickey', 'olivia', 'changeme', 'danielle', 'victoria', 'gabriel', '123456a', '0.00000000', 'loveyou', 'hockey', 'freedom', 'azerty', 'snoopy', 'skinny', 'myheritage', 'qwerty1', '159753', 'forever', 'iloveu', 'killer', 'joseph', 'master', 'mustang', 'hellokitty', 'school', 'Password1', 'patrick', 'blink182', 'tinkerbell', 'rainbow', 'nathan', 'cooper', 'onedirection', 'alexander', 'jordan23', 'lol123', 'jasper', 'junior', 'q1w2e3r4', '222222', '11111111', 'benjamin', 'jonathan', 'passw0rd', '123456789', 'a123456', 'samsung', '123', 'love123']

for i in range(len(hash_list)):
    found = False
    for pw in passlist:
        guess = hashlib.md5(pw.encode('utf-8')).hexdigest()
        if guess.lower() == hash_list[i]:
            print(f'Password for hash{i+1} is: {pw}')
            found = True
            continue
    if not found:
        print('The password is not found :(')
