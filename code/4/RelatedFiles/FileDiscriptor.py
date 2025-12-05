import os

class FileDescriptor:
    def __init__(self, filepath, mode='r', encoding='utf-8'):
        self.filepath = filepath
        self.mode = mode
        self.encoding = encoding
        self.file = None

    def open(self):
        self.file = open(self.filepath, self.mode, encoding=self.encoding)

    def read(self):
        if self.file is None:
            raise ValueError("File is not opened.")
        return self.file.read()

    def write(self, data):
        if self.file is None:
            raise ValueError("File is not opened.")
        self.file.write(data)

    def close(self):
        if self.file:
            self.file.close()
            self.file = None

    def get_size(self):
        return os.path.getsize(self.filepath)