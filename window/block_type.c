
#include "block_type.h"

/*  ####  */
w_block_data_t block1 = {
    .point1_x = 0,
    .point1_y = 0,
    .point2_x = 0,
    .point2_y = 1,
    .point3_x = 0,
    .point3_y = 2,
    .point4_x = 0,
    .point4_y = 3,
};
/*      ##
 *      ##
 */
w_block_data_t block2 = {
    .point1_x = 0,
    .point1_y = 0,
    .point2_x = 0,
    .point2_y = 1,
    .point3_x = 1,
    .point3_y = 0,
    .point4_x = 1,
    .point4_y = 1,
};
/*      ###
 *      #
 */
w_block_data_t block3 = {
    .point1_x = 0,
    .point1_y = 0,
    .point2_x = 0,
    .point2_y = 1,
    .point3_x = 0,
    .point3_y = 2,
    .point4_x = 1,
    .point4_y = 0,
};


w_block_data_t  *block_data[] = {
        &block1,&block2,&block3
};


w_block_data_t * get_block_data(int type)
{
    return block_data[type];
}



