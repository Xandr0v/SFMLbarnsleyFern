#include <iostream>
#include <SFML/graphics.hpp>
#include "Window.h"
Window w(1000, 1000, "barnsleyFern", 60);
sf::RenderWindow& window = w.window;


namespace m
{
    template<typename T>
	void print(sf::Vector2<T> v)
	{
		std::cout << v.x << " " << v.y << "\n";
	}
    template <typename T>
    void print(T a)
    {
        std::cout << a << "\n";
    }

	template <typename T>
	void print(T a, T b)
	{
		std::cout << a << " " << b << "\n";
	}
};



void setPixel(sf::Uint8* pixels, int x, int y, sf::Color col)
{
    if (0 < x && x < 1000 && 0 < y && y < 1000)
    {
        int i = x * 4 + y * 1000 * 4;
        pixels[i] = col.r;
        pixels[i + 1] = col.g;
        pixels[i + 2] = col.b;
        pixels[i + 3] = 255;
    }
}

struct coefficients
{
    float a, b, c, d, e, f, p;
};


void barnsleyFern(sf::Vector2f &p, coefficients l[])
{
    float r = (rand() % 100) / 100.f;
    float pr = l[0].p;
    for (int i = 0; i < 4; i++)
    {
        if (r < pr)
        {
            p = {
            l[i].a * p.x  +  l[i].b * p.y  +  l[i].e,
            l[i].c * p.x  +  l[i].d * p.y  +  l[i].f
            };
            return;
        }
        else
        {
            pr += l[i + 1].p;
        }
    }
}






int main()
{
    sf::Uint8* pixels = new sf::Uint8[1000 * 1000 * 4];

    sf::Texture texture;
    texture.create(1000, 1000);
    sf::Sprite sprite(texture);
    
    for (register int i = 0; i < 1000 * 1000 * 4; i += 4) {
        pixels[i] = 0; 
        pixels[i + 1] = 0;
        pixels[i + 2] = 0;
        pixels[i + 3] = 0;
    }

    


    coefficients l1[4]
    {
      //{ a    , b    , c    , d    , e    , f    , p   },
        { 0    , 0    , 0    , 0.16 , 0    , 0    , 0.01},
        { 0.85 , 0.04 ,-0.04 , 0.85 , 0    , 1.60 , 0.85},
        { 0.20 ,-0.26 , 0.23 , 0.22 , 0    , 1.60 , 0.07},
        {-0.15 , 0.28 , 0.26 , 0.24 , 0    , 0.44 , 0.07}
    };
    
    coefficients l2[4]
    {
        //{ a    , b    , c    , d    , e    , f    , p   },
          { 0    , 0    , 0    , 0.25 , 0    ,-0.4  , 0.02},
          { 0.95 , 0.005,-0.005, 0.93 ,-0.002, 0.5  , 0.84},
          { 0.035,-0.2  , 0.16 , 0.04 ,-0.09 , 0.02 , 0.07},
          {-0.04 , 0.2  , 0.16 , 0.04 , 0.083, 0.12 , 0.07}
    };
    coefficients l3[4]
    {
        //{ a    , b    , c    , d    , e    , f    , p   },
          { 0    , 0    , 0    , 0.25 , 0    ,-0.14 , 0.02},
          { 0.85 , 0.02 ,-0.02 , 0.83 , 0    , 1    , 0.84},
          { 0.09 ,-0.28 , 0.3  , 0.11 , 0    , 0.6  , 0.07},
          {-0.09 , 0.28 , 0.3  , 0.09 , 0    , 0.7  , 0.07}
    };


    sf::Vector2f p1(0, 0);
    sf::Vector2f p2(0, 0); 
    sf::Vector2f p3(0, 0);
    while (window.isOpen())
    {
        for (int i = 0; i < 100; i++)
        {
            barnsleyFern(p1, l1);
            setPixel(pixels, 200 + p1.x * 60, 950 - p1.y * 60, sf::Color(20, 230, 20));
        }
        for (int i = 0; i < 100; i++)
        {
            barnsleyFern(p2, l2);
            setPixel(pixels, 500 + p2.x * 80, 900 - p2.y * 80, sf::Color(120, 230, 0));
        }
        for (int i = 0; i < 100; i++)
        {
            barnsleyFern(p3, l3);
            setPixel(pixels, 800 + p3.x * 80, 950 - p3.y * 80, sf::Color(0, 255, 100));
        }
        texture.update(pixels);
        window.draw(sprite);
		w.update();
    }

    delete[] pixels;
    return 0;
}