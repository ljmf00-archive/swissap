"""
                                              _       _
                                             (_)     | |
  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_
 / __|/ _ \| | | | '__/ __/ _ \/ __|/ __| '__| | '_ \| __|
 \__ \ (_) | |_| | | | (_|  __/\__ \ (__| |  | | |_) | |_
 |___/\___/ \__,_|_|  \___\___||___/\___|_|  |_| .__/ \\__|
                                               | |
                                               |_|
            Copyright  (c) lsferreira programming - 20167

Forked from https://github.com/sarchar/addressgen
                                               """
                                               
                                               
""" base58 encoding / decoding functions """
import unittest
 
alphabet = '123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz'
base_count = len(alphabet)
        
def encode(num):
    """ Returns num in a base58-encoded string """
    encode = ''
    
    if (num < 0):
        return ''
    
    while (num >= base_count):    
        mod = num % base_count
        encode = alphabet[mod] + encode
        num = num // base_count
 
    if (num):
        encode = alphabet[num] + encode
 
    return encode
 
def decode(s):
    """ Decodes the base58-encoded string s into an integer """
    decoded = 0
    multi = 1
    s = s[::-1]
    for char in s:
        decoded += multi * alphabet.index(char)
        multi = multi * base_count
        
    return decoded
 
class Base58Tests(unittest.TestCase):
    def test_alphabet_length(self):
        self.assertEqual(58, len(alphabet))
    
    def test_encode_10002343_returns_Tgmc(self):
        result = encode(10002343)
        self.assertEqual('Tgmc', result)
    
    def test_decode_Tgmc_returns_10002343(self):
        decoded = decode('Tgmc')
        self.assertEqual(10002343, decoded)
    
    def test_encode_1000_returns_if(self):
        result = encode(1000)
        self.assertEqual('if', result)
    
    def test_decode_if_returns_1000(self):
        decoded = decode('if')
        self.assertEqual(1000, decoded)
    
    def test_encode_zero_returns_empty_string(self):
        self.assertEqual('', encode(0))
        
    def test_encode_negative_number_returns_empty_string(self):
        self.assertEqual('', encode(-100))
 
if __name__ == '__main__':
  unittest.main()
