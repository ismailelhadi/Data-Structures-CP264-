/*
 * your program signature
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avl.h"
#include "myrecord_avl.h"

void avl_merge(AVLNODE **dest_rootp, AVLNODE **source_rootp)
{
    if (source_rootp == NULL || *source_rootp == NULL)
        return;

    AVLNODE *node = *source_rootp;

    avl_merge(dest_rootp, &(node->left));  
    avl_insert(dest_rootp, node->data);   
    avl_merge(dest_rootp, &(node->right)); 
}

void avlds_merge(AVLDS *dest, AVLDS *source)
{
    if (source == NULL || source->count == 0)
        return;

    avl_merge(&(dest->root), &(source->root));

    int new_count = dest->count + source->count;
    if (new_count == 0)
        return;

    float new_mean = (dest->mean * dest->count + source->mean * source->count) / new_count;

    float dest_part = (dest->stddev * dest->stddev + dest->mean * dest->mean) * dest->count;
    float source_part = (source->stddev * source->stddev + source->mean * source->mean) * source->count;
    float new_stddev = sqrt((dest_part + source_part) / new_count - new_mean * new_mean);

    dest->count = new_count;
    dest->mean = new_mean;
    dest->stddev = new_stddev;

    avlds_clean(source);
}

void avlds_clean(AVLDS *ds)
{
    avl_clean(&ds->root);
    ds->count = 0;
    ds->mean = 0;
    ds->stddev = 0;
}

void add_record(AVLDS *tree, RECORD data)
{
    if (avl_search(tree->root, data.name) == NULL)
    {
        avl_insert(&(tree->root), data);
        int count = tree->count;
        float mean = tree->mean;
        float stddev = tree->stddev;
        tree->count = count + 1;
        tree->mean = (mean * count + data.score) / (count + 1.0);
        tree->stddev = sqrt(data.score * data.score / (count + 1.0) + (stddev * stddev + mean * mean) * (count / (count + 1.0)) - tree->mean * tree->mean);
    }
    else
    {
        printf("record exits");
    }
}

void remove_record(AVLDS *tree, char *name)
{
    AVLNODE *np = NULL;
    if ((np = avl_search(tree->root, name)) != NULL)
    {
        float score = np->data.score;
        avl_delete(&(tree->root), name);
        float count = tree->count;
        float mean = tree->mean;
        float stddev = tree->stddev;
        tree->count = count - 1;
        if (count >= 3)
        {
            tree->mean = (mean * count - score) / (count - 1.0);
            tree->stddev = sqrt((stddev * stddev + mean * mean) * (count / (count - 1.0)) - score * score / (count - 1.0) - tree->mean * tree->mean);
        }
        else if (count == 2)
        {
            tree->mean = mean * count - score;
            tree->stddev = 0;
        }
        else
        {
            tree->mean = 0;
            tree->stddev = 0;
        }
    }
    else
    {
        printf("record does not exit");
    }
}