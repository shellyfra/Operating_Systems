#include "aux_macro.h"
#include "../malloc_3.cpp"
#include <iostream>

void printStats()
                    {
                        std::cout << "_num_free_blocks: " << _num_free_blocks() << std::endl;
                        std::cout << "_num_free_bytes: " << _num_free_bytes() << std::endl;
                        std::cout << "_num_allocated_blocks: " << _num_allocated_blocks() << std::endl;
                        std::cout << "_num_allocated_bytes: " << _num_allocated_bytes() << std::endl;
                        std::cout << "_num_meta_data_bytes: " << _num_meta_data_bytes() << std::endl;
                        std::cout << "_size_meta_data: " << _size_meta_data() << std::endl;
                    }
                    int main()
                    {
                        PRINT_POINTER(smalloc(191););
printStats();
void* p0 = last_address;
PRINT_POINTER(scalloc(123,138););
printStats();
void* p1 = last_address;
PRINT_POINTER(srealloc(p0,19););
printStats();
void* p2 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
PRINT_POINTER(smalloc(114););
printStats();
void* p3 = last_address;
PRINT_POINTER(smalloc(248););
printStats();
void* p4 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p5 = last_address;
PRINT_POINTER(smalloc(138););
printStats();
void* p6 = last_address;
PRINT_POINTER(scalloc(182,99););
printStats();
void* p7 = last_address;
PRINT_POINTER(smalloc(13););
printStats();
void* p8 = last_address;
PRINT_POINTER(srealloc(p7,237););
printStats();
void* p9 = last_address;
PRINT_POINTER(scalloc(210,52););
printStats();
void* p10 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
DEBUG_PRINT(sfree(p1););
printStats();
PRINT_POINTER(scalloc(82,95););
printStats();
void* p11 = last_address;
DEBUG_PRINT(sfree(p9););
printStats();
DEBUG_PRINT(sfree(p10););
printStats();
DEBUG_PRINT(sfree(p11););
printStats();
PRINT_POINTER(scalloc(138,165););
printStats();
void* p12 = last_address;
PRINT_POINTER(srealloc(p4,228););
printStats();
void* p13 = last_address;
PRINT_POINTER(srealloc(p13,20););
printStats();
void* p14 = last_address;
DEBUG_PRINT(sfree(p12););
printStats();
PRINT_POINTER(scalloc(161,13););
printStats();
void* p15 = last_address;
PRINT_POINTER(srealloc(p14,178););
printStats();
void* p16 = last_address;
PRINT_POINTER(srealloc(p6,82););
printStats();
void* p17 = last_address;
DEBUG_PRINT(sfree(p5););
printStats();
PRINT_POINTER(scalloc(51,81););
printStats();
void* p18 = last_address;
DEBUG_PRINT(sfree(p17););
printStats();
DEBUG_PRINT(sfree(p18););
printStats();
PRINT_POINTER(srealloc(p16,174););
printStats();
void* p19 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
DEBUG_PRINT(sfree(p8););
printStats();
DEBUG_PRINT(sfree(p19););
printStats();
PRINT_POINTER(scalloc(119,42););
printStats();
void* p20 = last_address;
PRINT_POINTER(smalloc(176););
printStats();
void* p21 = last_address;
PRINT_POINTER(scalloc(42,204););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(srealloc(p21,224););
printStats();
void* p23 = last_address;
PRINT_POINTER(smalloc(118););
printStats();
void* p24 = last_address;
PRINT_POINTER(scalloc(243,39););
printStats();
void* p25 = last_address;
PRINT_POINTER(smalloc(113););
printStats();
void* p26 = last_address;
PRINT_POINTER(scalloc(53,62););
printStats();
void* p27 = last_address;
DEBUG_PRINT(sfree(p22););
printStats();
PRINT_POINTER(scalloc(54,2););
printStats();
void* p28 = last_address;
PRINT_POINTER(scalloc(22,56););
printStats();
void* p29 = last_address;
PRINT_POINTER(smalloc(174););
printStats();
void* p30 = last_address;
PRINT_POINTER(srealloc(p28,197););
printStats();
void* p31 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p32 = last_address;
PRINT_POINTER(scalloc(28,8););
printStats();
void* p33 = last_address;
PRINT_POINTER(srealloc(p23,97););
printStats();
void* p34 = last_address;
PRINT_POINTER(smalloc(161););
printStats();
void* p35 = last_address;
PRINT_POINTER(srealloc(p29,56););
printStats();
void* p36 = last_address;
PRINT_POINTER(srealloc(p32,167););
printStats();
void* p37 = last_address;
PRINT_POINTER(scalloc(135,196););
printStats();
void* p38 = last_address;
PRINT_POINTER(srealloc(p26,67););
printStats();
void* p39 = last_address;
PRINT_POINTER(smalloc(53););
printStats();
void* p40 = last_address;
PRINT_POINTER(smalloc(39););
printStats();
void* p41 = last_address;
PRINT_POINTER(scalloc(168,12););
printStats();
void* p42 = last_address;
PRINT_POINTER(scalloc(144,76););
printStats();
void* p43 = last_address;
PRINT_POINTER(srealloc(p38,71););
printStats();
void* p44 = last_address;
PRINT_POINTER(scalloc(179,249););
printStats();
void* p45 = last_address;
PRINT_POINTER(scalloc(206,43););
printStats();
void* p46 = last_address;
DEBUG_PRINT(sfree(p43););
printStats();
PRINT_POINTER(scalloc(200,190););
printStats();
void* p47 = last_address;
DEBUG_PRINT(sfree(p45););
printStats();
PRINT_POINTER(srealloc(p37,207););
printStats();
void* p48 = last_address;
PRINT_POINTER(smalloc(201););
printStats();
void* p49 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
DEBUG_PRINT(sfree(p35););
printStats();
PRINT_POINTER(smalloc(0););
printStats();
void* p50 = last_address;
DEBUG_PRINT(sfree(p24););
printStats();
PRINT_POINTER(scalloc(85,162););
printStats();
void* p51 = last_address;
PRINT_POINTER(smalloc(96););
printStats();
void* p52 = last_address;
DEBUG_PRINT(sfree(p42););
printStats();
PRINT_POINTER(smalloc(60););
printStats();
void* p53 = last_address;
DEBUG_PRINT(sfree(p39););
printStats();
PRINT_POINTER(smalloc(240););
printStats();
void* p54 = last_address;
PRINT_POINTER(srealloc(p36,117););
printStats();
void* p55 = last_address;
DEBUG_PRINT(sfree(p44););
printStats();
PRINT_POINTER(scalloc(93,149););
printStats();
void* p56 = last_address;
PRINT_POINTER(smalloc(122););
printStats();
void* p57 = last_address;
PRINT_POINTER(srealloc(p47,125););
printStats();
void* p58 = last_address;
PRINT_POINTER(srealloc(p30,99););
printStats();
void* p59 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
DEBUG_PRINT(sfree(p51););
printStats();
DEBUG_PRINT(sfree(p56););
printStats();
PRINT_POINTER(srealloc(p31,85););
printStats();
void* p60 = last_address;
PRINT_POINTER(scalloc(221,60););
printStats();
void* p61 = last_address;
PRINT_POINTER(srealloc(p41,151););
printStats();
void* p62 = last_address;
PRINT_POINTER(scalloc(8,210););
printStats();
void* p63 = last_address;
PRINT_POINTER(scalloc(46,104););
printStats();
void* p64 = last_address;
PRINT_POINTER(srealloc(p61,164););
printStats();
void* p65 = last_address;
PRINT_POINTER(srealloc(p53,48););
printStats();
void* p66 = last_address;
DEBUG_PRINT(sfree(p25););
printStats();
PRINT_POINTER(srealloc(p64,65););
printStats();
void* p67 = last_address;
PRINT_POINTER(scalloc(206,88););
printStats();
void* p68 = last_address;
PRINT_POINTER(scalloc(99,144););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(183););
printStats();
void* p70 = last_address;
DEBUG_PRINT(sfree(p52););
printStats();
PRINT_POINTER(scalloc(0,115););
printStats();
void* p71 = last_address;
PRINT_POINTER(smalloc(242););
printStats();
void* p72 = last_address;
DEBUG_PRINT(sfree(p70););
printStats();
PRINT_POINTER(smalloc(97););
printStats();
void* p73 = last_address;
PRINT_POINTER(srealloc(p48,233););
printStats();
void* p74 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
PRINT_POINTER(srealloc(p58,10););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(153,165););
printStats();
void* p76 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p77 = last_address;
PRINT_POINTER(srealloc(p68,205););
printStats();
void* p78 = last_address;
DEBUG_PRINT(sfree(p76););
printStats();
PRINT_POINTER(smalloc(10););
printStats();
void* p79 = last_address;
PRINT_POINTER(scalloc(163,170););
printStats();
void* p80 = last_address;
PRINT_POINTER(scalloc(23,61););
printStats();
void* p81 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
PRINT_POINTER(scalloc(122,72););
printStats();
void* p82 = last_address;
DEBUG_PRINT(sfree(p79););
printStats();
PRINT_POINTER(smalloc(57););
printStats();
void* p83 = last_address;
PRINT_POINTER(smalloc(121););
printStats();
void* p84 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
DEBUG_PRINT(sfree(p33););
printStats();
PRINT_POINTER(srealloc(p82,30););
printStats();
void* p85 = last_address;
PRINT_POINTER(smalloc(51););
printStats();
void* p86 = last_address;
PRINT_POINTER(srealloc(p69,209););
printStats();
void* p87 = last_address;
PRINT_POINTER(scalloc(40,249););
printStats();
void* p88 = last_address;
PRINT_POINTER(srealloc(p57,234););
printStats();
void* p89 = last_address;
PRINT_POINTER(smalloc(130););
printStats();
void* p90 = last_address;
PRINT_POINTER(srealloc(p88,242););
printStats();
void* p91 = last_address;
DEBUG_PRINT(sfree(p59););
printStats();
PRINT_POINTER(srealloc(p86,81););
printStats();
void* p92 = last_address;
PRINT_POINTER(srealloc(p65,113););
printStats();
void* p93 = last_address;
PRINT_POINTER(scalloc(140,84););
printStats();
void* p94 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
PRINT_POINTER(scalloc(245,230););
printStats();
void* p95 = last_address;
DEBUG_PRINT(sfree(p80););
printStats();
PRINT_POINTER(smalloc(221););
printStats();
void* p96 = last_address;
PRINT_POINTER(srealloc(p72,88););
printStats();
void* p97 = last_address;
PRINT_POINTER(smalloc(81););
printStats();
void* p98 = last_address;
PRINT_POINTER(scalloc(58,178););
printStats();
void* p99 = last_address;
PRINT_POINTER(scalloc(56,135););
printStats();
void* p100 = last_address;
DEBUG_PRINT(sfree(p99););
printStats();
PRINT_POINTER(smalloc(227););
printStats();
void* p101 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
PRINT_POINTER(smalloc(199););
printStats();
void* p102 = last_address;
PRINT_POINTER(srealloc(p101,68););
printStats();
void* p103 = last_address;
PRINT_POINTER(smalloc(69););
printStats();
void* p104 = last_address;
DEBUG_PRINT(sfree(p66););
printStats();
PRINT_POINTER(smalloc(91););
printStats();
void* p105 = last_address;
PRINT_POINTER(smalloc(4););
printStats();
void* p106 = last_address;
PRINT_POINTER(smalloc(240););
printStats();
void* p107 = last_address;
PRINT_POINTER(scalloc(0,112););
printStats();
void* p108 = last_address;
PRINT_POINTER(srealloc(p100,151););
printStats();
void* p109 = last_address;
PRINT_POINTER(scalloc(8,115););
printStats();
void* p110 = last_address;
PRINT_POINTER(srealloc(p62,18););
printStats();
void* p111 = last_address;
PRINT_POINTER(smalloc(116););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(149););
printStats();
void* p113 = last_address;
PRINT_POINTER(scalloc(16,14););
printStats();
void* p114 = last_address;
PRINT_POINTER(srealloc(p106,155););
printStats();
void* p115 = last_address;
DEBUG_PRINT(sfree(p75););
printStats();
PRINT_POINTER(smalloc(19););
printStats();
void* p116 = last_address;
PRINT_POINTER(smalloc(31););
printStats();
void* p117 = last_address;
PRINT_POINTER(smalloc(216););
printStats();
void* p118 = last_address;
PRINT_POINTER(srealloc(p81,0););
printStats();
void* p119 = last_address;
PRINT_POINTER(srealloc(p90,237););
printStats();
void* p120 = last_address;
PRINT_POINTER(srealloc(p91,33););
printStats();
void* p121 = last_address;
PRINT_POINTER(scalloc(137,190););
printStats();
void* p122 = last_address;
PRINT_POINTER(smalloc(97););
printStats();
void* p123 = last_address;
PRINT_POINTER(smalloc(25););
printStats();
void* p124 = last_address;
PRINT_POINTER(scalloc(125,47););
printStats();
void* p125 = last_address;
PRINT_POINTER(srealloc(p121,22););
printStats();
void* p126 = last_address;
DEBUG_PRINT(sfree(p102););
printStats();
PRINT_POINTER(smalloc(215););
printStats();
void* p127 = last_address;
PRINT_POINTER(smalloc(51););
printStats();
void* p128 = last_address;
PRINT_POINTER(scalloc(177,126););
printStats();
void* p129 = last_address;
PRINT_POINTER(scalloc(243,148););
printStats();
void* p130 = last_address;
DEBUG_PRINT(sfree(p123););
printStats();
PRINT_POINTER(smalloc(110););
printStats();
void* p131 = last_address;
PRINT_POINTER(smalloc(14););
printStats();
void* p132 = last_address;
DEBUG_PRINT(sfree(p60););
printStats();
DEBUG_PRINT(sfree(p122););
printStats();
PRINT_POINTER(smalloc(0););
printStats();
void* p133 = last_address;
PRINT_POINTER(srealloc(p110,27););
printStats();
void* p134 = last_address;
PRINT_POINTER(smalloc(205););
printStats();
void* p135 = last_address;
PRINT_POINTER(srealloc(p132,107););
printStats();
void* p136 = last_address;
DEBUG_PRINT(sfree(p105););
printStats();
PRINT_POINTER(scalloc(126,95););
printStats();
void* p137 = last_address;
PRINT_POINTER(srealloc(p131,128););
printStats();
void* p138 = last_address;
PRINT_POINTER(smalloc(105););
printStats();
void* p139 = last_address;
DEBUG_PRINT(sfree(p77););
printStats();
}
