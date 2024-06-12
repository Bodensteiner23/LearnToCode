import struct

# Open the .bin file in binary mode
with open('logfile.bin', 'rb') as f:
    content = f.read()

# Convert each group of 4 bytes to a float
float_values = [struct.unpack('f', content[i:i+4])[0] for i in range(0, len(content), 4)]

# Write these float values to a new file
with open('script.txt', 'w') as f:
    f.write(' '.join(map(str, float_values)))