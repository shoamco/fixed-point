//
// Created by shoam on 10/24/19.
//

#ifndef CPP_FIXED_POINT_SHOAMCO_COLOR_H
#define CPP_FIXED_POINT_SHOAMCO_COLOR_H




class Color {
public:
    template<class T>
    Color *calcFixedPointGradient(T num) {

        static Color pallette[num.Precision];//implicit interface
        int len= (sizeof(pallette)/sizeof(*pallette));


        return pallette;
    }

    template<class T>
    unsigned int getLenArry(T num) {

        static Color pallette[num.Precision];//implicit interface
        int len= (sizeof(pallette)/sizeof(*pallette));


        return num.Precision;
    }

};

#endif //CPP_FIXED_POINT_SHOAMCO_COLOR_H
