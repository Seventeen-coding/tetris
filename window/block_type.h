#ifndef BLOCK_TYPE_H
#define BLOCK_TYPE_H



typedef enum{
    BLOCK1,
    BLOCK2,
    BLOCK3,
    BLOCK4,
    BLOCK5,
    BLOCK6,
    BLOCK7,

    BLOCK_TYPE_NUM
}block_tpye_t;

typedef struct w_block_data_t{
    int point1_x;
    int point1_y;
    int point2_x;
    int point2_y;
    int point3_x;
    int point3_y;
    int point4_x;
    int point4_y;
}w_block_data_t;


w_block_data_t * get_block_data(int type);
#endif // BLOCK_TYPE_H

