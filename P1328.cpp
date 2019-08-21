#include <iostream>
using  namespace std;

enum {SCISSOR, STONE, CLOTH, LIZARD, SPOCK};

int N, NA, NB;

int value(int a, int b)
{
    switch(a)
    {
        case SCISSOR:
            if(b == CLOTH || b == LIZARD)
                return 1;
            else
                return 0;

        case STONE:
            if(b == SCISSOR || b == LIZARD)
                return 1;
            else
                return 0;

        case CLOTH:
            if(b == STONE || b == SPOCK)
                return 1;
            else
                return 0;

        case LIZARD:
            if(b == CLOTH || b == SPOCK)
                return 1;
            else
                return 0;

        case SPOCK:
            if(b == SCISSOR || b == STONE)
                return 1;
            else
                return 0;
    }
}

int main()
{
    cin >> N >> NA >> NB;

    int* turnA = new int[NA];
    int* turnB = new int[NB];

    for(int i=0; i<NA; ++i)
        cin >> turnA[i];
    for(int i=0; i<NB; ++i)
        cin >> turnB[i];

    int cntA = 0, cntB = 0;
    int scoreA = 0, scoreB = 0;

    for(int i=0; i<N; ++i)
    {
        if(turnA[cntA]!=turnB[cntB])
        {
            int score = value(turnA[cntA], turnB[cntB]);
            scoreA += score;
            scoreB += 1 - score;
        }


        cntA = (cntA + 1) % NA;
        cntB = (cntB + 1) % NB;
    }

    cout << scoreA << " " << scoreB;
}