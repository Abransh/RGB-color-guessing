#ifndef COLOR_HPP
#define COLOR_HPP

struct Color {
    int r, g, b;
    
    Color(int red = 0, int green = 0, int blue = 0);
    
    bool operator==(const Color& other) const;
};

#endif
