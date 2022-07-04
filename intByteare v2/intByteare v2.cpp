// intByteare v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class intByteare
{
public:
    intByteare()
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "intByteare() SAYS: Default constr. was called, default costr. is empty";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    intByteare(int& I)
    {
        fillUChArr_4(I);
    }
    ~intByteare()
    {
        delete pBoolArr_32;
    }

    // unsigned char section <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    void fillUChArr_4(int& I)
    {
        for (int i{ 0 }; i < 4; ++i)
        {
            uChArr_4[i] = ((I >> (3 - i) * 8) & 255);
        }
    }
    void showUCh(unsigned char& uCh)
    {
        for (int i = 7; i >= 0; i--)
        {
            if ((uCh >> i) & 1)
            {
                std::cout << "1";
            }
            else {
                std::cout << "0";
            }
        }
        std::cout << " ";
    }
    void showUChArr_4()
    {
        std::cout << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            showUCh(uChArr_4[i]);

        }
        std::cout << std::endl;
    }
    void mirrorUCh(unsigned char& uCh)
    {
        uCh = (uCh & 0xF0) >> 4 | (uCh & 0x0F) << 4;
        uCh = (uCh & 0xCC) >> 2 | (uCh & 0x33) << 2;
        uCh = (uCh & 0xAA) >> 1 | (uCh & 0x55) << 1;
    }

    // bool* section <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    bool* outputPBoolArr_32()
    {
        for (int i{ 0 }; i < 4; ++i)
        {
            //showUCh(uChArr_4[i]); //*show the unsigned char that is being processed
            mirrorUCh(uChArr_4[i]);
            for (int j{ 0 }; j < 8; j++)
            {
                if ((uChArr_4[i] >> j) & 1)
                {
                    pBoolArr_32[i * 8 + j] = 1;
                }
                else {
                    pBoolArr_32[i * 8 + j] = 0;
                }
            }
            mirrorUCh(uChArr_4[i]);
        }
        //std::cout << std::endl; //*used

        return pBoolArr_32;
    }

private:
    const int intMaxVal{ INT_MAX };
    const int bitN{ 1 };
    const int byteN{ 8 * bitN };
    const int intN{ 4 * byteN };
    int n_ints{ 1 };
    unsigned char uChArr_4[4]{};
    bool* pBoolArr_32 = new bool[32]{};
};


int main()
{
    // we create an int with the hight value of a signed int (01111111 11111111 11111111 11111111)
    std::cout << "type a possitive integer less than ";std::cout << INT_MAX; std::cout << " and press enter\n$  ";
        int I{ INT_MAX };
    std::cin >> I;
    if (I > INT_MAX || I < 0 || std::cin.fail())
    {
        std::cout << std::endl;
        std::cout << "Input was not expected";
        std::cout << std::endl;
        return 0;
    }

    // we create an object that intially converts the passed int to 4 unsigned chars (bytes, left to right) and stores them as an array
        
        intByteare a(I);

    // we use the object to creat a bool pointer, and the object gives a pointer to a new bool[32] with the same sequence as the unsigned chars
        
        bool* I_boolArray = a.outputPBoolArr_32();

    // we end by presenting the result
        
        std::cout << std::endl;
        std::cout << "integer: "; std::cout << I;
        std::cout << std::endl;
        std::cout << " binary: ";
        for (int i{ 0 }; i < 32; ++i)
        {
            if ((i > 0) && (i % 8 == 0))
            {
                std::cout << " ";
            }
            std::cout << I_boolArray[i];
        }
        std::cout << std::endl;

    return 0;
}

