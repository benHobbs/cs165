/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   3/16/2014
 ** Lab/Project#:   Exercise 17, Problem 1
 ** Filename:       maze.cpp
 ** Overview: 	    This program makes the user navigate a maze.
***************************************************************************************************/


#include <iostream>
#include <string>

class mapNode
{
public:
    mapNode(std::string name) : nodeName(name), south(NULL), north(NULL), west(NULL), east(NULL)
    {
        /*  Intentionally left blank  */
    }

    std::string getName() { return nodeName; };

    mapNode* getTouchingNode(char dir)
    {
        if(dir == 'S')
        {
            return south;
        }
        else if(dir == 'N')
        {
            return north;
        }
        else if(dir == 'W')
        {
            return west;
        }
        else if(dir == 'E')
        {
            return east;
        }
    }

    void linkMapNodes(char dir, mapNode *mn)
    {
        if(dir == 'S')
        {
            south = mn;
        }
        else if(dir == 'N')
        {
            north = mn;
        }
        else if(dir == 'W')
        {
            west = mn;
        }
        else if(dir == 'E')
        {
            east = mn;
        }
    }

    std::string getTouchingNodes()
    {
        std::string nodes = "";
        if(south != NULL)
        {
            nodes += "(S)";
        }
        if(north != NULL)
        {
            nodes += "(N)";
        }
        if(west != NULL)
        {
            nodes += "(W)";
        }
        if(east != NULL)
        {
            nodes += "(E)";
        }
        return nodes;
    }

private:
    std::string nodeName;
    mapNode *south, *north, *west, *east;
};

int main()
{
    mapNode *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l;
    a = new mapNode("A");
    b = new mapNode("B");
    c = new mapNode("C");
    d = new mapNode("D");
    e = new mapNode("E");
    f = new mapNode("F");
    g = new mapNode("G");
    h = new mapNode("H");
    i = new mapNode("I");
    j = new mapNode("J");
    k = new mapNode("K");
    l = new mapNode("L");

    a->linkMapNodes('S',e);
    a->linkMapNodes('E',b);
    b->linkMapNodes('S',f);
    c->linkMapNodes('E',d);
    c->linkMapNodes('S',g);
    d->linkMapNodes('W',c);
    e->linkMapNodes('N',a);
    e->linkMapNodes('S',i);
    f->linkMapNodes('N',b);
    f->linkMapNodes('E',g);
    g->linkMapNodes('W',f);
    g->linkMapNodes('S',k);
    g->linkMapNodes('N',c);
    g->linkMapNodes('E',h);
    h->linkMapNodes('W',g);
    h->linkMapNodes('S',l);
    i->linkMapNodes('N',e);
    i->linkMapNodes('E',j);
    j->linkMapNodes('W',i);
    k->linkMapNodes('N',g);
    l->linkMapNodes('N',h);


    mapNode *currentNode = a;

    do
    {
        std::cout << "You are in room " << currentNode->getName() << " of a maze of twisty little "
                  << "passages, all alike.\nYou can go " << currentNode->getTouchingNodes()
                  << ".\n";
        char input;
        std::cin >> input;

        mapNode* nextNode = currentNode->getTouchingNode(input);

        if(nextNode == NULL)
        {
            std::cout << "That direction is not a valid choice in the maze.\n";
        }
        else
        {
            currentNode = nextNode;
        }
    } while(currentNode->getName() != "L");

    std::cout << "You win, or at least you are able to get out of the maze." << std::endl;

    return 0;
}


