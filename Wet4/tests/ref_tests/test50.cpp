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
                        PRINT_POINTER(smalloc(94););
printStats();
void* p0 = last_address;
PRINT_POINTER(smalloc(115););
printStats();
void* p1 = last_address;
PRINT_POINTER(srealloc(p0,186););
printStats();
void* p2 = last_address;
PRINT_POINTER(smalloc(70););
printStats();
void* p3 = last_address;
PRINT_POINTER(scalloc(36,22););
printStats();
void* p4 = last_address;
PRINT_POINTER(smalloc(42););
printStats();
void* p5 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
DEBUG_PRINT(sfree(p1););
printStats();
PRINT_POINTER(scalloc(158,72););
printStats();
void* p6 = last_address;
PRINT_POINTER(smalloc(129););
printStats();
void* p7 = last_address;
PRINT_POINTER(scalloc(17,27););
printStats();
void* p8 = last_address;
PRINT_POINTER(srealloc(p5,49););
printStats();
void* p9 = last_address;
PRINT_POINTER(scalloc(35,133););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p10,85););
printStats();
void* p11 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
PRINT_POINTER(srealloc(p6,235););
printStats();
void* p12 = last_address;
PRINT_POINTER(scalloc(3,142););
printStats();
void* p13 = last_address;
DEBUG_PRINT(sfree(p9););
printStats();
DEBUG_PRINT(sfree(p11););
printStats();
PRINT_POINTER(srealloc(p8,176););
printStats();
void* p14 = last_address;
PRINT_POINTER(smalloc(135););
printStats();
void* p15 = last_address;
PRINT_POINTER(srealloc(p7,191););
printStats();
void* p16 = last_address;
DEBUG_PRINT(sfree(p16););
printStats();
DEBUG_PRINT(sfree(p12););
printStats();
PRINT_POINTER(scalloc(166,88););
printStats();
void* p17 = last_address;
PRINT_POINTER(smalloc(215););
printStats();
void* p18 = last_address;
PRINT_POINTER(scalloc(152,125););
printStats();
void* p19 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p20 = last_address;
DEBUG_PRINT(sfree(p14););
printStats();
PRINT_POINTER(scalloc(218,118););
printStats();
void* p21 = last_address;
PRINT_POINTER(scalloc(69,141););
printStats();
void* p22 = last_address;
PRINT_POINTER(srealloc(p20,37););
printStats();
void* p23 = last_address;
PRINT_POINTER(srealloc(p22,214););
printStats();
void* p24 = last_address;
PRINT_POINTER(scalloc(82,149););
printStats();
void* p25 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(smalloc(112););
printStats();
void* p26 = last_address;
PRINT_POINTER(smalloc(73););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(208,68););
printStats();
void* p28 = last_address;
DEBUG_PRINT(sfree(p28););
printStats();
PRINT_POINTER(srealloc(p23,231););
printStats();
void* p29 = last_address;
PRINT_POINTER(scalloc(70,226););
printStats();
void* p30 = last_address;
PRINT_POINTER(srealloc(p19,207););
printStats();
void* p31 = last_address;
PRINT_POINTER(srealloc(p13,236););
printStats();
void* p32 = last_address;
PRINT_POINTER(scalloc(80,51););
printStats();
void* p33 = last_address;
PRINT_POINTER(smalloc(60););
printStats();
void* p34 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(scalloc(137,133););
printStats();
void* p35 = last_address;
PRINT_POINTER(srealloc(p30,58););
printStats();
void* p36 = last_address;
PRINT_POINTER(smalloc(93););
printStats();
void* p37 = last_address;
PRINT_POINTER(srealloc(p4,247););
printStats();
void* p38 = last_address;
PRINT_POINTER(smalloc(49););
printStats();
void* p39 = last_address;
PRINT_POINTER(scalloc(76,215););
printStats();
void* p40 = last_address;
PRINT_POINTER(smalloc(210););
printStats();
void* p41 = last_address;
PRINT_POINTER(srealloc(p26,234););
printStats();
void* p42 = last_address;
PRINT_POINTER(smalloc(35););
printStats();
void* p43 = last_address;
PRINT_POINTER(srealloc(p42,193););
printStats();
void* p44 = last_address;
PRINT_POINTER(scalloc(179,32););
printStats();
void* p45 = last_address;
DEBUG_PRINT(sfree(p27););
printStats();
PRINT_POINTER(smalloc(7););
printStats();
void* p46 = last_address;
PRINT_POINTER(scalloc(101,104););
printStats();
void* p47 = last_address;
PRINT_POINTER(smalloc(224););
printStats();
void* p48 = last_address;
PRINT_POINTER(smalloc(45););
printStats();
void* p49 = last_address;
PRINT_POINTER(scalloc(132,248););
printStats();
void* p50 = last_address;
PRINT_POINTER(scalloc(209,156););
printStats();
void* p51 = last_address;
DEBUG_PRINT(sfree(p37););
printStats();
PRINT_POINTER(smalloc(115););
printStats();
void* p52 = last_address;
PRINT_POINTER(smalloc(50););
printStats();
void* p53 = last_address;
PRINT_POINTER(srealloc(p39,220););
printStats();
void* p54 = last_address;
PRINT_POINTER(scalloc(102,8););
printStats();
void* p55 = last_address;
DEBUG_PRINT(sfree(p53););
printStats();
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(smalloc(200););
printStats();
void* p56 = last_address;
DEBUG_PRINT(sfree(p56););
printStats();
PRINT_POINTER(smalloc(185););
printStats();
void* p57 = last_address;
PRINT_POINTER(smalloc(222););
printStats();
void* p58 = last_address;
PRINT_POINTER(srealloc(p25,152););
printStats();
void* p59 = last_address;
PRINT_POINTER(srealloc(p18,101););
printStats();
void* p60 = last_address;
PRINT_POINTER(smalloc(214););
printStats();
void* p61 = last_address;
PRINT_POINTER(srealloc(p38,206););
printStats();
void* p62 = last_address;
DEBUG_PRINT(sfree(p47););
printStats();
PRINT_POINTER(srealloc(p55,13););
printStats();
void* p63 = last_address;
PRINT_POINTER(srealloc(p48,142););
printStats();
void* p64 = last_address;
PRINT_POINTER(smalloc(2););
printStats();
void* p65 = last_address;
PRINT_POINTER(smalloc(36););
printStats();
void* p66 = last_address;
PRINT_POINTER(scalloc(66,235););
printStats();
void* p67 = last_address;
PRINT_POINTER(scalloc(48,118););
printStats();
void* p68 = last_address;
DEBUG_PRINT(sfree(p57););
printStats();
PRINT_POINTER(smalloc(102););
printStats();
void* p69 = last_address;
PRINT_POINTER(scalloc(193,239););
printStats();
void* p70 = last_address;
PRINT_POINTER(srealloc(p69,106););
printStats();
void* p71 = last_address;
PRINT_POINTER(scalloc(45,137););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(112,24););
printStats();
void* p73 = last_address;
PRINT_POINTER(smalloc(193););
printStats();
void* p74 = last_address;
PRINT_POINTER(srealloc(p17,189););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(118,42););
printStats();
void* p76 = last_address;
DEBUG_PRINT(sfree(p72););
printStats();
PRINT_POINTER(srealloc(p21,74););
printStats();
void* p77 = last_address;
PRINT_POINTER(scalloc(30,30););
printStats();
void* p78 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
DEBUG_PRINT(sfree(p66););
printStats();
PRINT_POINTER(srealloc(p52,60););
printStats();
void* p79 = last_address;
DEBUG_PRINT(sfree(p73););
printStats();
PRINT_POINTER(scalloc(139,27););
printStats();
void* p80 = last_address;
PRINT_POINTER(smalloc(220););
printStats();
void* p81 = last_address;
PRINT_POINTER(scalloc(193,174););
printStats();
void* p82 = last_address;
PRINT_POINTER(smalloc(48););
printStats();
void* p83 = last_address;
PRINT_POINTER(smalloc(176););
printStats();
void* p84 = last_address;
PRINT_POINTER(smalloc(179););
printStats();
void* p85 = last_address;
PRINT_POINTER(scalloc(35,7););
printStats();
void* p86 = last_address;
PRINT_POINTER(scalloc(104,56););
printStats();
void* p87 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
PRINT_POINTER(srealloc(p51,88););
printStats();
void* p88 = last_address;
PRINT_POINTER(smalloc(41););
printStats();
void* p89 = last_address;
PRINT_POINTER(srealloc(p80,118););
printStats();
void* p90 = last_address;
PRINT_POINTER(srealloc(p67,170););
printStats();
void* p91 = last_address;
PRINT_POINTER(smalloc(73););
printStats();
void* p92 = last_address;
DEBUG_PRINT(sfree(p60););
printStats();
PRINT_POINTER(smalloc(29););
printStats();
void* p93 = last_address;
PRINT_POINTER(scalloc(193,82););
printStats();
void* p94 = last_address;
PRINT_POINTER(smalloc(21););
printStats();
void* p95 = last_address;
DEBUG_PRINT(sfree(p64););
printStats();
DEBUG_PRINT(sfree(p81););
printStats();
PRINT_POINTER(scalloc(136,147););
printStats();
void* p96 = last_address;
PRINT_POINTER(smalloc(205););
printStats();
void* p97 = last_address;
PRINT_POINTER(srealloc(p93,42););
printStats();
void* p98 = last_address;
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(srealloc(p82,73););
printStats();
void* p99 = last_address;
PRINT_POINTER(smalloc(233););
printStats();
void* p100 = last_address;
PRINT_POINTER(srealloc(p76,158););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(241););
printStats();
void* p102 = last_address;
PRINT_POINTER(scalloc(135,194););
printStats();
void* p103 = last_address;
DEBUG_PRINT(sfree(p58););
printStats();
DEBUG_PRINT(sfree(p71););
printStats();
PRINT_POINTER(srealloc(p44,147););
printStats();
void* p104 = last_address;
PRINT_POINTER(scalloc(235,105););
printStats();
void* p105 = last_address;
PRINT_POINTER(srealloc(p45,53););
printStats();
void* p106 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
PRINT_POINTER(srealloc(p24,78););
printStats();
void* p107 = last_address;
PRINT_POINTER(smalloc(1););
printStats();
void* p108 = last_address;
PRINT_POINTER(srealloc(p68,113););
printStats();
void* p109 = last_address;
PRINT_POINTER(smalloc(144););
printStats();
void* p110 = last_address;
PRINT_POINTER(scalloc(86,132););
printStats();
void* p111 = last_address;
PRINT_POINTER(scalloc(97,207););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p113 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
PRINT_POINTER(srealloc(p105,54););
printStats();
void* p114 = last_address;
PRINT_POINTER(scalloc(240,73););
printStats();
void* p115 = last_address;
PRINT_POINTER(scalloc(199,60););
printStats();
void* p116 = last_address;
DEBUG_PRINT(sfree(p116););
printStats();
PRINT_POINTER(srealloc(p109,234););
printStats();
void* p117 = last_address;
DEBUG_PRINT(sfree(p29););
printStats();
PRINT_POINTER(srealloc(p70,133););
printStats();
void* p118 = last_address;
PRINT_POINTER(smalloc(154););
printStats();
void* p119 = last_address;
DEBUG_PRINT(sfree(p112););
printStats();
DEBUG_PRINT(sfree(p59););
printStats();
DEBUG_PRINT(sfree(p35););
printStats();
PRINT_POINTER(smalloc(138););
printStats();
void* p120 = last_address;
PRINT_POINTER(srealloc(p74,96););
printStats();
void* p121 = last_address;
PRINT_POINTER(scalloc(61,224););
printStats();
void* p122 = last_address;
DEBUG_PRINT(sfree(p111););
printStats();
PRINT_POINTER(smalloc(40););
printStats();
void* p123 = last_address;
PRINT_POINTER(srealloc(p43,135););
printStats();
void* p124 = last_address;
PRINT_POINTER(smalloc(82););
printStats();
void* p125 = last_address;
PRINT_POINTER(srealloc(p106,122););
printStats();
void* p126 = last_address;
PRINT_POINTER(srealloc(p88,94););
printStats();
void* p127 = last_address;
PRINT_POINTER(smalloc(236););
printStats();
void* p128 = last_address;
PRINT_POINTER(scalloc(136,5););
printStats();
void* p129 = last_address;
DEBUG_PRINT(sfree(p127););
printStats();
PRINT_POINTER(scalloc(22,25););
printStats();
void* p130 = last_address;
PRINT_POINTER(smalloc(103););
printStats();
void* p131 = last_address;
PRINT_POINTER(smalloc(162););
printStats();
void* p132 = last_address;
PRINT_POINTER(srealloc(p104,68););
printStats();
void* p133 = last_address;
PRINT_POINTER(srealloc(p36,9););
printStats();
void* p134 = last_address;
PRINT_POINTER(smalloc(156););
printStats();
void* p135 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p136 = last_address;
PRINT_POINTER(smalloc(18););
printStats();
void* p137 = last_address;
PRINT_POINTER(srealloc(p107,68););
printStats();
void* p138 = last_address;
PRINT_POINTER(srealloc(p92,116););
printStats();
void* p139 = last_address;
PRINT_POINTER(srealloc(p65,102););
printStats();
void* p140 = last_address;
PRINT_POINTER(scalloc(24,225););
printStats();
void* p141 = last_address;
PRINT_POINTER(smalloc(3););
printStats();
void* p142 = last_address;
DEBUG_PRINT(sfree(p102););
printStats();
DEBUG_PRINT(sfree(p41););
printStats();
PRINT_POINTER(scalloc(173,75););
printStats();
void* p143 = last_address;
PRINT_POINTER(srealloc(p132,249););
printStats();
void* p144 = last_address;
PRINT_POINTER(scalloc(219,137););
printStats();
void* p145 = last_address;
PRINT_POINTER(scalloc(40,138););
printStats();
void* p146 = last_address;
DEBUG_PRINT(sfree(p110););
printStats();
PRINT_POINTER(scalloc(236,62););
printStats();
void* p147 = last_address;
PRINT_POINTER(scalloc(17,141););
printStats();
void* p148 = last_address;
PRINT_POINTER(srealloc(p135,193););
printStats();
void* p149 = last_address;
PRINT_POINTER(smalloc(60););
printStats();
void* p150 = last_address;
PRINT_POINTER(smalloc(124););
printStats();
void* p151 = last_address;
PRINT_POINTER(scalloc(96,6););
printStats();
void* p152 = last_address;
PRINT_POINTER(smalloc(190););
printStats();
void* p153 = last_address;
PRINT_POINTER(srealloc(p54,87););
printStats();
void* p154 = last_address;
PRINT_POINTER(scalloc(193,17););
printStats();
void* p155 = last_address;
PRINT_POINTER(srealloc(p94,30););
printStats();
void* p156 = last_address;
PRINT_POINTER(scalloc(228,71););
printStats();
void* p157 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p158 = last_address;
PRINT_POINTER(srealloc(p133,117););
printStats();
void* p159 = last_address;
PRINT_POINTER(scalloc(191,131););
printStats();
void* p160 = last_address;
PRINT_POINTER(scalloc(91,82););
printStats();
void* p161 = last_address;
PRINT_POINTER(srealloc(p156,59););
printStats();
void* p162 = last_address;
PRINT_POINTER(scalloc(144,125););
printStats();
void* p163 = last_address;
PRINT_POINTER(smalloc(122););
printStats();
void* p164 = last_address;
PRINT_POINTER(srealloc(p95,99););
printStats();
void* p165 = last_address;
DEBUG_PRINT(sfree(p145););
printStats();
PRINT_POINTER(smalloc(2););
printStats();
void* p166 = last_address;
}
