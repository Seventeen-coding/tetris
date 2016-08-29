#include "w_text.h"

static  int  __w_init( w_text_t  * _this);

static  int __w_msg ( void *__this,char arg);
static  int  __w_show(void *__this);
static  int  __w_hide ( void *__this);
static  int  __w_select ( void *__this,char arg);
static  int  __w_destory ( void *__this);

int    __w_set_text(void *__this, const char *src_text);



//static int __set_text();


w_text_t * window_create_text(window_t *parent,int x,int y,int w,int h)
{
    w_text_t  * text =  (w_text_t  *)malloc(sizeof(w_text_t ));
    window_t * window = _w_create_window(parent,x,y,w,h);
    text->window = window;
    __w_init(text);

    return (w_text_t *)text;
}

static  int  __w_init(w_text_t  * _this)
{
    _this->function.destory = __w_destory;
    _this->function.show = __w_show;
    _this->function.hide = __w_hide;
    _this->function.select = __w_select;
    _this->function.msg = __w_msg;
    _this->function.set_text = __w_set_text;
    return 0;
}


static int __w_select(void *__this,char key)
{
    return TEXT_NEXT;
}


static  int  __w_show( void *__this)
{
    w_text_t *text = (w_text_t *)__this;
    system("color 30");         //以后可以用不同的颜色去表示
    int x = text->window->data.__x;
    int y = text->window->data.__y;
    //printline
    text->data.index = 0;
    while(text->data.index < text->window->data.__w * text->window->data.__h && text->data.index <  text->data.len)
    {
        if( (text->data.index % text->window->data.__w)  == 0)
        {
            gotoXY(x,y++);
        }
        if(text->data.text[text->data.index]  != ' ')  printf("%c",text->data.text[text->data.index]);
        text->data.index++;
    }
    //show chlidren
    //text->window->function.show(text->window);        //以后再需要开启
    return 0;
}

int     __w_hide(void*__this)
{
    w_text_t *text = (w_text_t *)__this;
    system("color 30");
    gotoXY(text->window->data.__x,text->window->data.__y);
    //需要优化
    int i ;
    for(i = 0 ;i< text->data.len;i++)   printf(" ");
    return 0;
}

static int __w_msg(void *__this,char msg)
{

    return 0;
}
static int __w_destory(void *__this)
{

    return 0;
}

int    __w_set_text(void *__this, const char *src_text)
{
    w_text_t *text = (w_text_t *) __this;
    text->data.len = strlen(src_text);
    if(text->data.text != NULL) free(text->data.text);
    text->data.text = (char *)malloc(text->data.len + 1);
    strcpy(text->data.text,src_text);
    return 0;
}

