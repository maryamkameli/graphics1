// ppm_read.cpp
#include <iostream>
#include <fstream>
#include <string>

using std::cerr;
using std::cout;
using std::ifstream;
using std::string;

static bool next_token(ifstream& in, string& tok) {
    // Skip whitespace and #comment lines
    while (true) {
        int c = in.peek();
        if (c == '#') {
            // discard the whole comment line
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (std::isspace(c)) {
            in.get();
        } else {
            break;
        }
        if (!in) return false;
    }
    return (in >> tok) ? true : false;
}

int main(int argc, char** argv) {
    string path = (argc > 1) ? argv[1] : "test.ppm";
    ifstream ppmFile(path);
    if (!ppmFile) {
        cerr << "Error: couldn't open file: " << path << "\n";
        return 1;
    }

    string magic;
    if (!next_token(ppmFile, magic) || magic != "P3") {
        cerr << "Error: only ASCII PPM (P3) supported. Magic read: '" << magic << "'\n";
        return 1;
    }

    string tok;
    int w = 0, h = 0, maxVal = 0;

    if (!next_token(ppmFile, tok)) { cerr << "Error reading width\n"; return 1; }
    w = std::stoi(tok);
    if (!next_token(ppmFile, tok)) { cerr << "Error reading height\n"; return 1; }
    h = std::stoi(tok);
    if (!next_token(ppmFile, tok)) { cerr << "Error reading maxVal\n"; return 1; }
    maxVal = std::stoi(tok);

    cout << "PPM Type: " << magic
         << ". Image size " << w << " x " << h
         << ". Max Val: " << maxVal << "\n";

    int expected = w * h;
    for (int i = 0; i < expected; ++i) {
        string rs, gs, bs;
        if (!next_token(ppmFile, rs) || !next_token(ppmFile, gs) || !next_token(ppmFile, bs)) {
            cerr << "Error: ran out of pixel data at pixel " << i << "\n";
            return 1;
        }
        int r = std::stoi(rs), g = std::stoi(gs), b = std::stoi(bs);
        if (r < 0 || r > maxVal || g < 0 || g > maxVal || b < 0 || b > maxVal) {
            cerr << "Error: pixel " << i << " has out-of-range value(s)\n";
            return 1;
        }
        // Print or process pixels; comment out the next line if it's too verbose
        // cout << "Pixel# " << i << "  R:" << r << " G:" << g << " B:" << b << "\n";
    }

    cout << "Read " << expected << " pixels successfully.\n";
    return 0;
}