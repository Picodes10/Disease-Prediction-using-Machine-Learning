import pytesseract
from PIL import Image
import io
from pdf2image import convert_from_bytes

pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'  # for Windows


def extract_text_from_file(file):
    if file.filename.endswith('.pdf'):
        images = convert_from_bytes(file.read())
        text = ''
        for img in images:
            text += pytesseract.image_to_string(img)
        return text
    else:
        image = Image.open(file.stream)
        return pytesseract.image_to_string(image)
