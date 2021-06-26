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
                        PRINT_POINTER(scalloc(228,206););
printStats();
void* p0 = last_address;
PRINT_POINTER(scalloc(157,116););
printStats();
void* p1 = last_address;
PRINT_POINTER(srealloc(p0,216););
printStats();
void* p2 = last_address;
PRINT_POINTER(scalloc(57,87););
printStats();
void* p3 = last_address;
PRINT_POINTER(srealloc(p2,161););
printStats();
void* p4 = last_address;
PRINT_POINTER(scalloc(23,113););
printStats();
void* p5 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(srealloc(p5,98););
printStats();
void* p6 = last_address;
DEBUG_PRINT(sfree(p1););
printStats();
PRINT_POINTER(scalloc(247,30););
printStats();
void* p7 = last_address;
PRINT_POINTER(smalloc(35););
printStats();
void* p8 = last_address;
PRINT_POINTER(srealloc(p8,50););
printStats();
void* p9 = last_address;
PRINT_POINTER(srealloc(p7,244););
printStats();
void* p10 = last_address;
DEBUG_PRINT(sfree(p10););
printStats();
PRINT_POINTER(scalloc(160,195););
printStats();
void* p11 = last_address;
PRINT_POINTER(smalloc(35););
printStats();
void* p12 = last_address;
DEBUG_PRINT(sfree(p11););
printStats();
PRINT_POINTER(smalloc(104););
printStats();
void* p13 = last_address;
PRINT_POINTER(srealloc(p13,218););
printStats();
void* p14 = last_address;
PRINT_POINTER(srealloc(p14,173););
printStats();
void* p15 = last_address;
PRINT_POINTER(srealloc(p6,17););
printStats();
void* p16 = last_address;
PRINT_POINTER(srealloc(p16,20););
printStats();
void* p17 = last_address;
PRINT_POINTER(scalloc(119,105););
printStats();
void* p18 = last_address;
PRINT_POINTER(smalloc(181););
printStats();
void* p19 = last_address;
PRINT_POINTER(srealloc(p12,36););
printStats();
void* p20 = last_address;
DEBUG_PRINT(sfree(p19););
printStats();
PRINT_POINTER(srealloc(p17,67););
printStats();
void* p21 = last_address;
PRINT_POINTER(smalloc(89););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p18););
printStats();
PRINT_POINTER(srealloc(p20,94););
printStats();
void* p23 = last_address;
PRINT_POINTER(smalloc(209););
printStats();
void* p24 = last_address;
PRINT_POINTER(scalloc(47,33););
printStats();
void* p25 = last_address;
PRINT_POINTER(scalloc(189,28););
printStats();
void* p26 = last_address;
PRINT_POINTER(srealloc(p21,167););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(247,185););
printStats();
void* p28 = last_address;
DEBUG_PRINT(sfree(p9););
printStats();
PRINT_POINTER(scalloc(30,104););
printStats();
void* p29 = last_address;
PRINT_POINTER(smalloc(46););
printStats();
void* p30 = last_address;
PRINT_POINTER(smalloc(109););
printStats();
void* p31 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(smalloc(118););
printStats();
void* p32 = last_address;
PRINT_POINTER(srealloc(p25,204););
printStats();
void* p33 = last_address;
DEBUG_PRINT(sfree(p27););
printStats();
PRINT_POINTER(smalloc(115););
printStats();
void* p34 = last_address;
DEBUG_PRINT(sfree(p29););
printStats();
PRINT_POINTER(smalloc(58););
printStats();
void* p35 = last_address;
DEBUG_PRINT(sfree(p24););
printStats();
DEBUG_PRINT(sfree(p26););
printStats();
PRINT_POINTER(srealloc(p32,15););
printStats();
void* p36 = last_address;
PRINT_POINTER(smalloc(161););
printStats();
void* p37 = last_address;
PRINT_POINTER(srealloc(p22,47););
printStats();
void* p38 = last_address;
PRINT_POINTER(scalloc(91,47););
printStats();
void* p39 = last_address;
PRINT_POINTER(scalloc(48,20););
printStats();
void* p40 = last_address;
PRINT_POINTER(scalloc(159,231););
printStats();
void* p41 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
PRINT_POINTER(smalloc(193););
printStats();
void* p42 = last_address;
DEBUG_PRINT(sfree(p35););
printStats();
PRINT_POINTER(smalloc(112););
printStats();
void* p43 = last_address;
PRINT_POINTER(srealloc(p39,101););
printStats();
void* p44 = last_address;
PRINT_POINTER(smalloc(31););
printStats();
void* p45 = last_address;
PRINT_POINTER(smalloc(23););
printStats();
void* p46 = last_address;
PRINT_POINTER(smalloc(219););
printStats();
void* p47 = last_address;
PRINT_POINTER(srealloc(p45,186););
printStats();
void* p48 = last_address;
PRINT_POINTER(smalloc(147););
printStats();
void* p49 = last_address;
DEBUG_PRINT(sfree(p37););
printStats();
PRINT_POINTER(smalloc(102););
printStats();
void* p50 = last_address;
PRINT_POINTER(srealloc(p31,160););
printStats();
void* p51 = last_address;
PRINT_POINTER(scalloc(220,34););
printStats();
void* p52 = last_address;
PRINT_POINTER(scalloc(77,21););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(225,133););
printStats();
void* p54 = last_address;
PRINT_POINTER(srealloc(p28,213););
printStats();
void* p55 = last_address;
DEBUG_PRINT(sfree(p30););
printStats();
PRINT_POINTER(srealloc(p51,13););
printStats();
void* p56 = last_address;
PRINT_POINTER(scalloc(56,24););
printStats();
void* p57 = last_address;
PRINT_POINTER(smalloc(79););
printStats();
void* p58 = last_address;
PRINT_POINTER(srealloc(p48,223););
printStats();
void* p59 = last_address;
DEBUG_PRINT(sfree(p41););
printStats();
DEBUG_PRINT(sfree(p50););
printStats();
PRINT_POINTER(srealloc(p43,1););
printStats();
void* p60 = last_address;
DEBUG_PRINT(sfree(p57););
printStats();
PRINT_POINTER(scalloc(224,67););
printStats();
void* p61 = last_address;
PRINT_POINTER(srealloc(p58,12););
printStats();
void* p62 = last_address;
PRINT_POINTER(srealloc(p38,85););
printStats();
void* p63 = last_address;
DEBUG_PRINT(sfree(p56););
printStats();
DEBUG_PRINT(sfree(p42););
printStats();
PRINT_POINTER(scalloc(51,168););
printStats();
void* p64 = last_address;
PRINT_POINTER(smalloc(31););
printStats();
void* p65 = last_address;
PRINT_POINTER(scalloc(43,107););
printStats();
void* p66 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
PRINT_POINTER(srealloc(p53,110););
printStats();
void* p67 = last_address;
DEBUG_PRINT(sfree(p52););
printStats();
PRINT_POINTER(scalloc(226,87););
printStats();
void* p68 = last_address;
PRINT_POINTER(smalloc(229););
printStats();
void* p69 = last_address;
DEBUG_PRINT(sfree(p67););
printStats();
DEBUG_PRINT(sfree(p59););
printStats();
PRINT_POINTER(scalloc(116,44););
printStats();
void* p70 = last_address;
PRINT_POINTER(scalloc(238,243););
printStats();
void* p71 = last_address;
DEBUG_PRINT(sfree(p68););
printStats();
PRINT_POINTER(smalloc(141););
printStats();
void* p72 = last_address;
DEBUG_PRINT(sfree(p66););
printStats();
DEBUG_PRINT(sfree(p60););
printStats();
PRINT_POINTER(scalloc(183,191););
printStats();
void* p73 = last_address;
PRINT_POINTER(scalloc(76,148););
printStats();
void* p74 = last_address;
PRINT_POINTER(srealloc(p44,93););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(66,240););
printStats();
void* p76 = last_address;
PRINT_POINTER(scalloc(103,161););
printStats();
void* p77 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
PRINT_POINTER(srealloc(p54,36););
printStats();
void* p78 = last_address;
DEBUG_PRINT(sfree(p71););
printStats();
PRINT_POINTER(smalloc(191););
printStats();
void* p79 = last_address;
PRINT_POINTER(scalloc(244,123););
printStats();
void* p80 = last_address;
PRINT_POINTER(srealloc(p65,218););
printStats();
void* p81 = last_address;
DEBUG_PRINT(sfree(p74););
printStats();
PRINT_POINTER(scalloc(92,22););
printStats();
void* p82 = last_address;
PRINT_POINTER(scalloc(37,143););
printStats();
void* p83 = last_address;
PRINT_POINTER(srealloc(p49,207););
printStats();
void* p84 = last_address;
PRINT_POINTER(smalloc(22););
printStats();
void* p85 = last_address;
DEBUG_PRINT(sfree(p34););
printStats();
DEBUG_PRINT(sfree(p73););
printStats();
PRINT_POINTER(scalloc(46,8););
printStats();
void* p86 = last_address;
PRINT_POINTER(smalloc(59););
printStats();
void* p87 = last_address;
PRINT_POINTER(scalloc(196,186););
printStats();
void* p88 = last_address;
PRINT_POINTER(srealloc(p79,0););
printStats();
void* p89 = last_address;
DEBUG_PRINT(sfree(p64););
printStats();
PRINT_POINTER(smalloc(239););
printStats();
void* p90 = last_address;
DEBUG_PRINT(sfree(p77););
printStats();
PRINT_POINTER(scalloc(151,150););
printStats();
void* p91 = last_address;
PRINT_POINTER(smalloc(80););
printStats();
void* p92 = last_address;
PRINT_POINTER(scalloc(205,194););
printStats();
void* p93 = last_address;
PRINT_POINTER(smalloc(26););
printStats();
void* p94 = last_address;
PRINT_POINTER(scalloc(184,142););
printStats();
void* p95 = last_address;
PRINT_POINTER(smalloc(155););
printStats();
void* p96 = last_address;
PRINT_POINTER(scalloc(110,23););
printStats();
void* p97 = last_address;
PRINT_POINTER(srealloc(p80,163););
printStats();
void* p98 = last_address;
PRINT_POINTER(srealloc(p63,143););
printStats();
void* p99 = last_address;
PRINT_POINTER(srealloc(p83,179););
printStats();
void* p100 = last_address;
PRINT_POINTER(smalloc(168););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(37););
printStats();
void* p102 = last_address;
DEBUG_PRINT(sfree(p72););
printStats();
PRINT_POINTER(srealloc(p88,133););
printStats();
void* p103 = last_address;
PRINT_POINTER(scalloc(116,18););
printStats();
void* p104 = last_address;
DEBUG_PRINT(sfree(p69););
printStats();
PRINT_POINTER(scalloc(47,75););
printStats();
void* p105 = last_address;
PRINT_POINTER(scalloc(2,8););
printStats();
void* p106 = last_address;
PRINT_POINTER(scalloc(94,102););
printStats();
void* p107 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
PRINT_POINTER(scalloc(77,211););
printStats();
void* p108 = last_address;
PRINT_POINTER(srealloc(p84,7););
printStats();
void* p109 = last_address;
PRINT_POINTER(scalloc(208,141););
printStats();
void* p110 = last_address;
PRINT_POINTER(srealloc(p47,206););
printStats();
void* p111 = last_address;
DEBUG_PRINT(sfree(p91););
printStats();
PRINT_POINTER(scalloc(245,156););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(26););
printStats();
void* p113 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(srealloc(p82,53););
printStats();
void* p114 = last_address;
PRINT_POINTER(srealloc(p113,26););
printStats();
void* p115 = last_address;
PRINT_POINTER(srealloc(p94,68););
printStats();
void* p116 = last_address;
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(scalloc(35,117););
printStats();
void* p117 = last_address;
DEBUG_PRINT(sfree(p107););
printStats();
DEBUG_PRINT(sfree(p76););
printStats();
PRINT_POINTER(scalloc(4,60););
printStats();
void* p118 = last_address;
PRINT_POINTER(scalloc(134,84););
printStats();
void* p119 = last_address;
PRINT_POINTER(scalloc(86,6););
printStats();
void* p120 = last_address;
PRINT_POINTER(srealloc(p36,205););
printStats();
void* p121 = last_address;
PRINT_POINTER(scalloc(76,229););
printStats();
void* p122 = last_address;
DEBUG_PRINT(sfree(p112););
printStats();
PRINT_POINTER(smalloc(158););
printStats();
void* p123 = last_address;
PRINT_POINTER(smalloc(102););
printStats();
void* p124 = last_address;
DEBUG_PRINT(sfree(p118););
printStats();
PRINT_POINTER(scalloc(73,224););
printStats();
void* p125 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
DEBUG_PRINT(sfree(p124););
printStats();
PRINT_POINTER(scalloc(59,176););
printStats();
void* p126 = last_address;
DEBUG_PRINT(sfree(p115););
printStats();
DEBUG_PRINT(sfree(p116););
printStats();
PRINT_POINTER(scalloc(177,218););
printStats();
void* p127 = last_address;
PRINT_POINTER(smalloc(150););
printStats();
void* p128 = last_address;
PRINT_POINTER(smalloc(14););
printStats();
void* p129 = last_address;
PRINT_POINTER(scalloc(112,121););
printStats();
void* p130 = last_address;
DEBUG_PRINT(sfree(p99););
printStats();
PRINT_POINTER(smalloc(180););
printStats();
void* p131 = last_address;
DEBUG_PRINT(sfree(p75););
printStats();
DEBUG_PRINT(sfree(p121););
printStats();
PRINT_POINTER(scalloc(45,215););
printStats();
void* p132 = last_address;
PRINT_POINTER(smalloc(159););
printStats();
void* p133 = last_address;
PRINT_POINTER(srealloc(p128,133););
printStats();
void* p134 = last_address;
PRINT_POINTER(smalloc(17););
printStats();
void* p135 = last_address;
DEBUG_PRINT(sfree(p78););
printStats();
PRINT_POINTER(scalloc(139,239););
printStats();
void* p136 = last_address;
PRINT_POINTER(smalloc(106););
printStats();
void* p137 = last_address;
PRINT_POINTER(scalloc(190,249););
printStats();
void* p138 = last_address;
DEBUG_PRINT(sfree(p132););
printStats();
DEBUG_PRINT(sfree(p138););
printStats();
DEBUG_PRINT(sfree(p103););
printStats();
DEBUG_PRINT(sfree(p70););
printStats();
PRINT_POINTER(srealloc(p95,143););
printStats();
void* p139 = last_address;
PRINT_POINTER(smalloc(232););
printStats();
void* p140 = last_address;
PRINT_POINTER(smalloc(78););
printStats();
void* p141 = last_address;
DEBUG_PRINT(sfree(p137););
printStats();
PRINT_POINTER(scalloc(18,92););
printStats();
void* p142 = last_address;
PRINT_POINTER(scalloc(16,5););
printStats();
void* p143 = last_address;
DEBUG_PRINT(sfree(p120););
printStats();
PRINT_POINTER(scalloc(26,100););
printStats();
void* p144 = last_address;
PRINT_POINTER(scalloc(234,73););
printStats();
void* p145 = last_address;
PRINT_POINTER(srealloc(p104,194););
printStats();
void* p146 = last_address;
DEBUG_PRINT(sfree(p123););
printStats();
PRINT_POINTER(scalloc(220,48););
printStats();
void* p147 = last_address;
PRINT_POINTER(smalloc(156););
printStats();
void* p148 = last_address;
DEBUG_PRINT(sfree(p143););
printStats();
DEBUG_PRINT(sfree(p114););
printStats();
PRINT_POINTER(srealloc(p90,59););
printStats();
void* p149 = last_address;
PRINT_POINTER(smalloc(45););
printStats();
void* p150 = last_address;
PRINT_POINTER(scalloc(35,69););
printStats();
void* p151 = last_address;
PRINT_POINTER(scalloc(180,185););
printStats();
void* p152 = last_address;
DEBUG_PRINT(sfree(p142););
printStats();
PRINT_POINTER(scalloc(127,77););
printStats();
void* p153 = last_address;
PRINT_POINTER(scalloc(155,180););
printStats();
void* p154 = last_address;
DEBUG_PRINT(sfree(p33););
printStats();
DEBUG_PRINT(sfree(p92););
printStats();
PRINT_POINTER(smalloc(181););
printStats();
void* p155 = last_address;
PRINT_POINTER(scalloc(8,23););
printStats();
void* p156 = last_address;
DEBUG_PRINT(sfree(p144););
printStats();
PRINT_POINTER(scalloc(48,54););
printStats();
void* p157 = last_address;
PRINT_POINTER(scalloc(226,37););
printStats();
void* p158 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
PRINT_POINTER(scalloc(160,38););
printStats();
void* p159 = last_address;
PRINT_POINTER(scalloc(239,14););
printStats();
void* p160 = last_address;
PRINT_POINTER(smalloc(190););
printStats();
void* p161 = last_address;
PRINT_POINTER(srealloc(p130,170););
printStats();
void* p162 = last_address;
DEBUG_PRINT(sfree(p97););
printStats();
PRINT_POINTER(smalloc(37););
printStats();
void* p163 = last_address;
DEBUG_PRINT(sfree(p133););
printStats();
DEBUG_PRINT(sfree(p62););
printStats();
PRINT_POINTER(smalloc(129););
printStats();
void* p164 = last_address;
DEBUG_PRINT(sfree(p109););
printStats();
PRINT_POINTER(smalloc(106););
printStats();
void* p165 = last_address;
PRINT_POINTER(srealloc(p108,137););
printStats();
void* p166 = last_address;
PRINT_POINTER(srealloc(p119,120););
printStats();
void* p167 = last_address;
PRINT_POINTER(scalloc(111,78););
printStats();
void* p168 = last_address;
PRINT_POINTER(scalloc(20,200););
printStats();
void* p169 = last_address;
PRINT_POINTER(srealloc(p161,23););
printStats();
void* p170 = last_address;
DEBUG_PRINT(sfree(p169););
printStats();
DEBUG_PRINT(sfree(p145););
printStats();
PRINT_POINTER(scalloc(235,147););
printStats();
void* p171 = last_address;
PRINT_POINTER(scalloc(10,92););
printStats();
void* p172 = last_address;
PRINT_POINTER(smalloc(1););
printStats();
void* p173 = last_address;
PRINT_POINTER(smalloc(201););
printStats();
void* p174 = last_address;
PRINT_POINTER(srealloc(p140,94););
printStats();
void* p175 = last_address;
PRINT_POINTER(smalloc(212););
printStats();
void* p176 = last_address;
PRINT_POINTER(scalloc(206,165););
printStats();
void* p177 = last_address;
PRINT_POINTER(smalloc(76););
printStats();
void* p178 = last_address;
PRINT_POINTER(smalloc(81););
printStats();
void* p179 = last_address;
PRINT_POINTER(scalloc(210,203););
printStats();
void* p180 = last_address;
PRINT_POINTER(smalloc(11););
printStats();
void* p181 = last_address;
PRINT_POINTER(srealloc(p89,234););
printStats();
void* p182 = last_address;
PRINT_POINTER(smalloc(137););
printStats();
void* p183 = last_address;
PRINT_POINTER(smalloc(181););
printStats();
void* p184 = last_address;
PRINT_POINTER(srealloc(p151,14););
printStats();
void* p185 = last_address;
DEBUG_PRINT(sfree(p154););
printStats();
PRINT_POINTER(smalloc(75););
printStats();
void* p186 = last_address;
PRINT_POINTER(scalloc(60,160););
printStats();
void* p187 = last_address;
PRINT_POINTER(srealloc(p180,175););
printStats();
void* p188 = last_address;
PRINT_POINTER(srealloc(p182,127););
printStats();
void* p189 = last_address;
PRINT_POINTER(scalloc(75,202););
printStats();
void* p190 = last_address;
PRINT_POINTER(scalloc(131,21););
printStats();
void* p191 = last_address;
}
