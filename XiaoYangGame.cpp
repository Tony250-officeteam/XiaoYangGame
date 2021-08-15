#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
/**********************变量定义区******************************/
int message = 0;//全场广播，当为1->wayh2g,2->gils,3->wayg2gf,4->gf,5->waygf2cor,6->coress,7->clock
int x, y;
string title;//地图的名字。
char z; //地图的大小、纹理。
int xx, xy; //小样的坐标
int dx, dy; //门的坐标，当都是114514的时候，没有门
int dax, day;//伤害的坐标,与 dx dy规则一致。
int Gcishu = 6;//girl中的游戏回合的数量，不用改了。
/************************************************************/
/**********************函数定义区******************************/
void girl();
void girlGame(int ddx, int ddy);//girl部分中的游戏的部分，因为需要重复，所以使用函数表达。
void wayG2Gf();
void GF();
void wayGF2cor();
void coress();
void clocker();
void clean();//清屏
void check();
void direct();//键盘的操作
void t();//让子弹飞一会
void gameHome();//包括前情和小样的房屋
void ot(string name, string message); //消息栏的输出（包括回车的提示）
void draw();//地形的绘制
void drawG();
void start();//游戏开始界面
void wayH2G();
/***********************************************************/
int main() {//这是我见过最没用的main函数
    start();
    //    gameHome();//注意，这里仅仅做调试时使用，当进行阶段性发布的时候，须改为 start();
    //    girl();
}
/*********************功能区*********************************/
void clean() {
    system("cls");
}
void t() {
    Sleep(100);
}
void direct() {
    char temp = getchar();
    if (temp == 'w') {
        getchar();
        xx -= 1;
        if (xx < 0) {
            xx = 0;
        }
        draw();
    }

    if (temp == 's') {
        getchar();
        xx += 1;
        if (xx > y - 1) {
            xx -= 1;
        }
        draw();
    }

    if (temp == 'd') {
        getchar();
        xy += 1;
        if (xy > x - 1) {
            xy -= 1;
        }
        draw();
    }

    if (temp == 'q') {
        getchar();
        clean();
        start();
    }

    if (temp == 'a') {
        getchar();
        xy -= 1;
        if (xy < 0) {
            xy = 0;
        }
        draw();
    }
    else {
        if (xx + 1 == dy && xy + 1 == dx) {
            xx = 0;
            xy = 0;
            dx = 10;
            dy = 2;
            message += 1;
            check();
        }
        else {
            draw();
        }
    }
}
void ot(string name, string message) {
    cout << "\n\n\n\n\n\n\n\n";
    cout << "---------------------------------------------------------------" << endl;
    cout << "消息栏" << endl;
    cout << name << ":" << endl;
    cout << message << endl;
    cout << "（点击回车得以继续）";
    getchar();
    clean();

}
void draw() {
    system("cls");
    cout << "\n\n\n\n" << title << "\n\n        ";
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (i == xx && j == xy) {
                cout << "R ";
                continue;
            }
            if (i == dy - 1 && j == dx - 1 && dx != 114514 && dy != 114514) {
                cout << "D ";
                continue;
            }
            cout << z << " ";
        }
        cout << "\n        ";
    }
    cout << "\n\n---------------------------------------\n命令行：";
    direct();
}
void drawG() {
    system("cls");
    cout << "\n\n\n\n" << title << "\n\n        ";
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (i == xx - 1 && j == xy - 1) {
                cout << "R ";
                continue;
            }
            if (i == day - 1 && j == dax - 1 && dax != 114514 && day != 114514) {
                cout << "* ";
                continue;
            }
            cout << z << " ";
        }
        cout << "\n        ";
    }
}
void  check() {
    switch (message) {//全场广播，当为1->wayh2g,2->gils,3->wayg2gf,4->gf,5->waygf2cor,6->coress,7->clock
    case 1:wayH2G(); break;
    case 2:girl(); break;
    case 3:wayG2Gf(); break;
    case 4:GF(); break;
    case 5:wayGF2cor(); break;
    case 6:coress(); break;
    case 7:clocker(); break;
    }
}
void girlGame(int ddx, int ddy) {
    day = ddy;
    dax = ddx;
    if (xy == dax && xx == day) {
        drawG();
        cout << "\n\n---------------------------------------\n对不起，你已经死了~\n点击回车返回开始界面……";
        getchar();
        getchar();
        clean();
        start();
    }
    else {
        drawG();
        Gcishu--;
        if (Gcishu == 0) {
            cout << "\n\n---------------------------------------\n已存活。游戏回合还剩：" << Gcishu << " 点击回车退出小女孩的游戏。" << "\n命令行：";
            getchar();
            getchar();
            message++;
            check();
        }
        else {
            cout << "\n\n---------------------------------------\n已存活。游戏回合还剩：" << Gcishu << "\n命令行：";
            cin >> xy >> xx;
        }
    }
}
/**********************************************************/
/*********************技术区********************************/
void start() {
    cout << "\n\n\n\n\n\n";
    cout << "                                          小样の大冒险                                          \n";
    Sleep(100);
    cout << "\n\n\n\n\n\n";
    Sleep(100);
    cout << "                                       [点击a回车]开始游戏                                        \n\n";
    Sleep(100);
    cout << "                                       [点击b回车]继续游戏(暂不开放）                             \n\n";
    Sleep(100);
    cout << "                                       [点击c回车]关于游戏                                        \n\n";
    Sleep(100);
    cout << "                                       [点击d回车]关闭游戏                                        \n\n";
    switch (getchar()) {
    case 'a': {
        getchar();
        system("cls");
        gameHome();
        break;
    }

    case 'b': {
        getchar();
        system("cls");
        cout << "抱歉，现在还没有开发出存档功能！！";
        Sleep(200);
        system("cls");
        start();
        break;
    }

    case 'c': {
        getchar();
        system("cls");
        cout << "游戏：小样の大冒险，由office工作室、吃瓜队长所有\n\n";
        Sleep(100);
        cout << "游戏灵感：矮人要塞 p.s.说实话，在我最先开始看到有这么一个游戏的时候,";
        Sleep(100);
        cout << "我是震惊的，因为我从来没有想到，我竟然可以使用命令行来制作游戏，哈，";
        Sleep(100);
        cout << "没想到还蛮不错的，我的qt技术算是白学的\n\n当你看到这一串文字的时候，";
        Sleep(100);
        cout << "我坚信，这个游戏他还没有完结，这个游戏当它完结的时候，他会有五大关\n\n";
        Sleep(100);
        cout << "分别是：小女孩、小区大爷，过马路，小混混、开门\n\n";
        Sleep(100);
        cout << "我认为你会觉得这个游戏蛮有意思的\n\n";
        Sleep(100);
        cout << "祝您游戏愉快！！               by：吃瓜队长\n\n\n\n";
        Sleep(100);
        cout << "使用：在Clion中的c++语言\n\n";
        Sleep(100);
        cout << "(点击回车进行退出)\n\n";
        getchar();
        system("cls");
        start();
        break;
    }

    case 'd': {
        getchar();
        system("cls");
        exit(0);
        break;
    }

    default: {
        getchar();
        system("cls");
        start();
        break;
    }
    }
}          //没事不要打开，太长了。
void gameHome() {
    t();
    string temp = "“啊啊，好无聊呀！”陈小样这样想着，这几天，小豌豌和白蕊都出去了，"
        "房子里面也就仅仅只有他一个人了,变成了人走房空,很显然，这几天"
        "他无法和小豌豌一同去往工作室。";
    string temp2 = "“啊啊，也只能自己前往了……”陈小样这样想着，起了床……";
    string temp3 = "游戏提示：注意，游戏中的所有地图之类的，都是由字母构成的，因为这个世界就是由代码构成的"
        "，其中， o 是地板和地面 ， w 是 草， D 是门，触碰到 * 会死亡，就像是真正的世界一样，您只有一条生"
        "命,游戏的操作依靠指令，w 为向上 ，s 为向下，a 为向左，d 为向右, q 为返回至游戏界面"
        "。p.s.其实是因为瓜队的懒";
    ot("旁白", temp);
    ot("旁白", temp2);
    ot("旁白", temp3);
    dx = 10;
    dy = 5;
    x = 10;
    y = 10;
    z = 'o';
    title = "陈小样的家";
    xx = 0;
    xy = 0;
    draw();
}
void wayH2G() {
    xx = 0;
    xy = 0;
    dx = 10;
    dy = 2;
    x = 10;
    y = 3;
    title = "田间小路";
    z = 'w';
    draw();
}
void girl() {
    clean();
    ot("旁白", "路上，一个小女孩走了过来……");
    ot("小女孩", "大哥哥，我一个人好无聊呀~");
    ot("陈小样", "【停了下来】干什么？");
    ot("小女孩", "你陪陪我……");
    ot("小女孩", "【拿出菜刀】玩游戏吧！");
    ot("旁白", "捉迷藏：游戏规则");
    ot("旁白", "输入坐标进行躲藏");
    ot("旁白", "捉迷藏：如果小女孩的坐标和你的坐标是一致的，则她会杀了你。");
    ot("旁白", "游戏坐标例如初始点坐标就是【1 1】，以下边，右边为正方向");
    ot("旁白", "输入范例：");
    ot("旁白", "1 1");
    xx = 1;
    xy = 1;
    x = 9;
    y = 9;
    z = 'o';
    dx = 114514;
    dy = 114514;
    title = "捉迷藏";
    girlGame(2, 2);
    girlGame(1, 4);
    girlGame(1, 5);
    girlGame(9, 2);
    girlGame(6, 5);
    girlGame(3, 5);

}
void wayG2Gf() {
    clean();
    ot("小女孩", "哼，大哥哥没意思！");
    ot("陈小样", "真是虚惊一场~");
    ot("旁白", "恭喜你完成了这一款游戏！");
    ot("旁白", "这仅仅是一个测试版");
    ot("旁白", "我们会在后期增加更多的关卡和情节的，希望你这次玩得开心");
    ot("旁白", "点击回车以返回至游戏开始界面。");
    start();
}
void GF() {}
void wayGF2cor() {}
void coress() {}
void clocker() {}
/**********************************************************/