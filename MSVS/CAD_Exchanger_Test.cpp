
#include <iostream>

#include "Curve.h"

#include <vector>

#include <algorithm>

const double PI = 3.1415926535897932384626433832795;

const double RAND_TO_1 = 1 / double(RAND_MAX);

int main()
{
    std::vector<curv::ICurve*> firstCont;
    std::vector<curv::ICurve*> secondCont;

    double sp[]{
        -1, 1, 2, 5,
        0, 1, 1, 2,
        0, 0, 1, -3
    };

    for(int i = 0; i < 1000 ; i++)
    {
        curv::ICurve *t;
        for(int j = 0; j < 12; j++)
            sp[j] = rand() * RAND_TO_1 * 200 - 100;
        switch((rand() % 3))
        {
            case 0:
            {
                t = new curv::Circle(sp, rand() * RAND_TO_1 * 10);
            }
            break;
            case 1:
            {
                t = new curv::Ellipse(sp, rand() * RAND_TO_1 * 10, rand() * RAND_TO_1 * 10);
            }
            break;
            case 2:
            {
                t = new curv::Helixe(sp, rand() * RAND_TO_1 * 10, rand() * RAND_TO_1 * 10);
            }
            break;
            default:
            break;
        }
        firstCont.push_back(t);
        
    }
    double point[3];
    for(int i = 0; i < firstCont.size(); i++)
    {
        firstCont[i]->GetPoint(PI * 0.25, point);
        printf("P_%i = {%f, %f, %f}\n", i, point[0], point[1], point[2]);

        curv::Circle* d = dynamic_cast<curv::Circle*>(firstCont[i]); 
        if(d != nullptr)
        {
            secondCont.push_back(d);
        }
    }

    std::sort
    (
        secondCont.begin(), 
        secondCont.end(), 
        [](curv::ICurve* a, curv::ICurve* b) 
        {
            return ((curv::Circle*)(a))->GetR() < ((curv::Circle*)(b))->GetR();
        }
    );

    double summ = 0;

    for(int i = 0; i < secondCont.size(); i++)
    {
        summ += ((curv::Circle *)(secondCont[i]))->GetR();
    }
    printf("first sorted radius = %f\n", ((curv::Circle *)(secondCont[0]))->GetR());
    printf("last sorted radius = %f\n", ((curv::Circle *)(secondCont[secondCont.size() - 1]))->GetR());


    printf("Summ of radius = %f\n", summ);

    return 0;
}
