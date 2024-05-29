import hashlib

def generate_checksum(file_path):
    sha256_hash = hashlib.sha256()
    with open(file_path, "rb") as f:
        for byte_block in iter(lambda: f.read(4096), b""):
            sha256_hash.update(byte_block)
    return sha256_hash.hexdigest()

file_path = 'filename.cpp'
with open('checksum.txt', 'r') as f:
    original_checksum = f.read().strip()

current_checksum = generate_checksum(file_path)
if current_checksum == original_checksum:
    print(f"{file_path} is unchanged.")
else:
    print(f"{file_path} has been modified!")
