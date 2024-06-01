#include <iostream>
#include <qrencode.h>
#include <fstream>

void saveToPBM(QRcode *qrcode, const std::string &filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    const int size = qrcode->width;
    file << "P4\n" << size << " " << size << "\n";

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (qrcode->data[y * size + x] & 1) {
                file.put(0);
            } else {
                file.put(1);
            }
        }
    }

    file.close();
}

int main() {
    std::string text = "https://example.com";
    QRcode *qrcode = QRcode_encodeString(text.c_str(), 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == nullptr) {
        std::cerr << "Failed to generate QR code" << std::endl;
        return 1;
    }

    saveToPBM(qrcode, "qrcode.pbm");

    QRcode_free(qrcode);
    std::cout << "QR code generated and saved to qrcode.pbm" << std::endl;

    return 0;
}
