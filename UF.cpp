#include "UF.h"


using namespace std;

bool UF::same_component(int x, int y) const
{
    return (findp(x) ==  findp(y));

}
int UF::findp(int x) const
{
    if(parents[x] == x)
        return x;
    
    return findp(parents[x]);
}
void UF::unions(int x, int y)
{

    int px = findp(x);
    int py = findp(y);
    if(tree_size[x] >= tree_size[y])
    {
        parents[y] = px;
        tree_size[x] += tree_size[y];
    }
    else if(tree_size[x] < tree_size[y] )
    {
        parents[x] = py;
        tree_size[y] += tree_size[x];
    }
    return;
}
