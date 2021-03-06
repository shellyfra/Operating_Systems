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
                        PRINT_POINTER(scalloc(65,117););
printStats();
void* p0 = last_address;
PRINT_POINTER(srealloc(p0,139););
printStats();
void* p1 = last_address;
PRINT_POINTER(scalloc(169,216););
printStats();
void* p2 = last_address;
PRINT_POINTER(smalloc(81););
printStats();
void* p3 = last_address;
PRINT_POINTER(srealloc(p1,248););
printStats();
void* p4 = last_address;
PRINT_POINTER(scalloc(122,118););
printStats();
void* p5 = last_address;
PRINT_POINTER(scalloc(211,66););
printStats();
void* p6 = last_address;
PRINT_POINTER(srealloc(p5,103););
printStats();
void* p7 = last_address;
PRINT_POINTER(scalloc(90,92););
printStats();
void* p8 = last_address;
PRINT_POINTER(smalloc(92););
printStats();
void* p9 = last_address;
PRINT_POINTER(srealloc(p7,187););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p4,148););
printStats();
void* p11 = last_address;
PRINT_POINTER(smalloc(247););
printStats();
void* p12 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
PRINT_POINTER(smalloc(237););
printStats();
void* p13 = last_address;
PRINT_POINTER(srealloc(p13,184););
printStats();
void* p14 = last_address;
PRINT_POINTER(smalloc(171););
printStats();
void* p15 = last_address;
PRINT_POINTER(scalloc(86,46););
printStats();
void* p16 = last_address;
DEBUG_PRINT(sfree(p14););
printStats();
PRINT_POINTER(smalloc(122););
printStats();
void* p17 = last_address;
PRINT_POINTER(scalloc(34,93););
printStats();
void* p18 = last_address;
PRINT_POINTER(smalloc(211););
printStats();
void* p19 = last_address;
PRINT_POINTER(smalloc(44););
printStats();
void* p20 = last_address;
DEBUG_PRINT(sfree(p11););
printStats();
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(smalloc(122););
printStats();
void* p21 = last_address;
PRINT_POINTER(srealloc(p8,126););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(srealloc(p9,45););
printStats();
void* p23 = last_address;
DEBUG_PRINT(sfree(p18););
printStats();
DEBUG_PRINT(sfree(p22););
printStats();
PRINT_POINTER(smalloc(177););
printStats();
void* p24 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
DEBUG_PRINT(sfree(p17););
printStats();
DEBUG_PRINT(sfree(p16););
printStats();
PRINT_POINTER(scalloc(73,42););
printStats();
void* p25 = last_address;
PRINT_POINTER(smalloc(195););
printStats();
void* p26 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p27 = last_address;
PRINT_POINTER(smalloc(70););
printStats();
void* p28 = last_address;
PRINT_POINTER(srealloc(p26,0););
printStats();
void* p29 = last_address;
PRINT_POINTER(srealloc(p25,13););
printStats();
void* p30 = last_address;
PRINT_POINTER(smalloc(209););
printStats();
void* p31 = last_address;
PRINT_POINTER(smalloc(101););
printStats();
void* p32 = last_address;
PRINT_POINTER(smalloc(239););
printStats();
void* p33 = last_address;
PRINT_POINTER(scalloc(125,129););
printStats();
void* p34 = last_address;
PRINT_POINTER(srealloc(p23,161););
printStats();
void* p35 = last_address;
PRINT_POINTER(scalloc(52,190););
printStats();
void* p36 = last_address;
PRINT_POINTER(srealloc(p27,242););
printStats();
void* p37 = last_address;
DEBUG_PRINT(sfree(p19););
printStats();
PRINT_POINTER(scalloc(19,71););
printStats();
void* p38 = last_address;
PRINT_POINTER(smalloc(82););
printStats();
void* p39 = last_address;
PRINT_POINTER(smalloc(60););
printStats();
void* p40 = last_address;
DEBUG_PRINT(sfree(p30););
printStats();
DEBUG_PRINT(sfree(p36););
printStats();
PRINT_POINTER(scalloc(119,164););
printStats();
void* p41 = last_address;
DEBUG_PRINT(sfree(p21););
printStats();
PRINT_POINTER(srealloc(p10,229););
printStats();
void* p42 = last_address;
PRINT_POINTER(scalloc(239,197););
printStats();
void* p43 = last_address;
PRINT_POINTER(srealloc(p37,107););
printStats();
void* p44 = last_address;
PRINT_POINTER(scalloc(83,204););
printStats();
void* p45 = last_address;
PRINT_POINTER(srealloc(p45,82););
printStats();
void* p46 = last_address;
PRINT_POINTER(smalloc(167););
printStats();
void* p47 = last_address;
PRINT_POINTER(scalloc(178,17););
printStats();
void* p48 = last_address;
PRINT_POINTER(srealloc(p6,18););
printStats();
void* p49 = last_address;
PRINT_POINTER(smalloc(178););
printStats();
void* p50 = last_address;
PRINT_POINTER(scalloc(27,160););
printStats();
void* p51 = last_address;
DEBUG_PRINT(sfree(p51););
printStats();
PRINT_POINTER(smalloc(176););
printStats();
void* p52 = last_address;
PRINT_POINTER(scalloc(143,203););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(12,96););
printStats();
void* p54 = last_address;
PRINT_POINTER(scalloc(137,105););
printStats();
void* p55 = last_address;
PRINT_POINTER(srealloc(p48,209););
printStats();
void* p56 = last_address;
PRINT_POINTER(srealloc(p39,94););
printStats();
void* p57 = last_address;
PRINT_POINTER(scalloc(136,180););
printStats();
void* p58 = last_address;
PRINT_POINTER(srealloc(p58,235););
printStats();
void* p59 = last_address;
PRINT_POINTER(srealloc(p47,170););
printStats();
void* p60 = last_address;
PRINT_POINTER(smalloc(220););
printStats();
void* p61 = last_address;
PRINT_POINTER(srealloc(p44,169););
printStats();
void* p62 = last_address;
PRINT_POINTER(smalloc(187););
printStats();
void* p63 = last_address;
PRINT_POINTER(scalloc(81,157););
printStats();
void* p64 = last_address;
PRINT_POINTER(scalloc(237,40););
printStats();
void* p65 = last_address;
DEBUG_PRINT(sfree(p65););
printStats();
PRINT_POINTER(scalloc(55,40););
printStats();
void* p66 = last_address;
PRINT_POINTER(srealloc(p62,66););
printStats();
void* p67 = last_address;
PRINT_POINTER(smalloc(89););
printStats();
void* p68 = last_address;
PRINT_POINTER(scalloc(6,174););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(33););
printStats();
void* p70 = last_address;
PRINT_POINTER(scalloc(45,190););
printStats();
void* p71 = last_address;
PRINT_POINTER(srealloc(p70,33););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(42,163););
printStats();
void* p73 = last_address;
PRINT_POINTER(srealloc(p68,102););
printStats();
void* p74 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
PRINT_POINTER(srealloc(p24,249););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(62,138););
printStats();
void* p76 = last_address;
PRINT_POINTER(srealloc(p52,191););
printStats();
void* p77 = last_address;
DEBUG_PRINT(sfree(p31););
printStats();
DEBUG_PRINT(sfree(p53););
printStats();
DEBUG_PRINT(sfree(p57););
printStats();
PRINT_POINTER(scalloc(131,245););
printStats();
void* p78 = last_address;
DEBUG_PRINT(sfree(p63););
printStats();
PRINT_POINTER(smalloc(36););
printStats();
void* p79 = last_address;
DEBUG_PRINT(sfree(p73););
printStats();
PRINT_POINTER(smalloc(7););
printStats();
void* p80 = last_address;
PRINT_POINTER(srealloc(p74,157););
printStats();
void* p81 = last_address;
PRINT_POINTER(srealloc(p42,59););
printStats();
void* p82 = last_address;
DEBUG_PRINT(sfree(p81););
printStats();
PRINT_POINTER(srealloc(p43,72););
printStats();
void* p83 = last_address;
PRINT_POINTER(srealloc(p56,135););
printStats();
void* p84 = last_address;
PRINT_POINTER(scalloc(205,103););
printStats();
void* p85 = last_address;
DEBUG_PRINT(sfree(p64););
printStats();
PRINT_POINTER(smalloc(178););
printStats();
void* p86 = last_address;
PRINT_POINTER(srealloc(p72,51););
printStats();
void* p87 = last_address;
PRINT_POINTER(smalloc(222););
printStats();
void* p88 = last_address;
PRINT_POINTER(scalloc(77,22););
printStats();
void* p89 = last_address;
PRINT_POINTER(scalloc(46,52););
printStats();
void* p90 = last_address;
PRINT_POINTER(scalloc(54,221););
printStats();
void* p91 = last_address;
DEBUG_PRINT(sfree(p84););
printStats();
PRINT_POINTER(scalloc(122,215););
printStats();
void* p92 = last_address;
DEBUG_PRINT(sfree(p61););
printStats();
PRINT_POINTER(smalloc(54););
printStats();
void* p93 = last_address;
PRINT_POINTER(smalloc(231););
printStats();
void* p94 = last_address;
PRINT_POINTER(srealloc(p59,55););
printStats();
void* p95 = last_address;
PRINT_POINTER(scalloc(182,220););
printStats();
void* p96 = last_address;
PRINT_POINTER(smalloc(205););
printStats();
void* p97 = last_address;
PRINT_POINTER(scalloc(26,40););
printStats();
void* p98 = last_address;
PRINT_POINTER(scalloc(76,100););
printStats();
void* p99 = last_address;
PRINT_POINTER(srealloc(p83,219););
printStats();
void* p100 = last_address;
PRINT_POINTER(scalloc(29,20););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(56););
printStats();
void* p102 = last_address;
PRINT_POINTER(srealloc(p76,5););
printStats();
void* p103 = last_address;
PRINT_POINTER(smalloc(123););
printStats();
void* p104 = last_address;
PRINT_POINTER(srealloc(p69,66););
printStats();
void* p105 = last_address;
PRINT_POINTER(srealloc(p77,11););
printStats();
void* p106 = last_address;
PRINT_POINTER(scalloc(88,29););
printStats();
void* p107 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p108 = last_address;
PRINT_POINTER(srealloc(p60,240););
printStats();
void* p109 = last_address;
PRINT_POINTER(srealloc(p105,195););
printStats();
void* p110 = last_address;
DEBUG_PRINT(sfree(p75););
printStats();
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(smalloc(42););
printStats();
void* p111 = last_address;
PRINT_POINTER(srealloc(p95,24););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(187););
printStats();
void* p113 = last_address;
PRINT_POINTER(scalloc(179,189););
printStats();
void* p114 = last_address;
PRINT_POINTER(scalloc(144,97););
printStats();
void* p115 = last_address;
PRINT_POINTER(srealloc(p86,12););
printStats();
void* p116 = last_address;
PRINT_POINTER(srealloc(p102,95););
printStats();
void* p117 = last_address;
PRINT_POINTER(smalloc(12););
printStats();
void* p118 = last_address;
PRINT_POINTER(srealloc(p93,43););
printStats();
void* p119 = last_address;
PRINT_POINTER(srealloc(p110,29););
printStats();
void* p120 = last_address;
PRINT_POINTER(srealloc(p78,218););
printStats();
void* p121 = last_address;
PRINT_POINTER(srealloc(p101,48););
printStats();
void* p122 = last_address;
PRINT_POINTER(scalloc(139,51););
printStats();
void* p123 = last_address;
PRINT_POINTER(srealloc(p116,82););
printStats();
void* p124 = last_address;
DEBUG_PRINT(sfree(p94););
printStats();
PRINT_POINTER(smalloc(99););
printStats();
void* p125 = last_address;
PRINT_POINTER(scalloc(85,12););
printStats();
void* p126 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
PRINT_POINTER(smalloc(214););
printStats();
void* p127 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p128 = last_address;
DEBUG_PRINT(sfree(p124););
printStats();
PRINT_POINTER(smalloc(123););
printStats();
void* p129 = last_address;
PRINT_POINTER(srealloc(p88,232););
printStats();
void* p130 = last_address;
PRINT_POINTER(scalloc(239,43););
printStats();
void* p131 = last_address;
DEBUG_PRINT(sfree(p122););
printStats();
PRINT_POINTER(smalloc(177););
printStats();
void* p132 = last_address;
PRINT_POINTER(scalloc(245,3););
printStats();
void* p133 = last_address;
PRINT_POINTER(smalloc(87););
printStats();
void* p134 = last_address;
PRINT_POINTER(srealloc(p91,103););
printStats();
void* p135 = last_address;
PRINT_POINTER(srealloc(p12,57););
printStats();
void* p136 = last_address;
PRINT_POINTER(smalloc(208););
printStats();
void* p137 = last_address;
PRINT_POINTER(srealloc(p132,182););
printStats();
void* p138 = last_address;
PRINT_POINTER(scalloc(116,167););
printStats();
void* p139 = last_address;
PRINT_POINTER(srealloc(p117,69););
printStats();
void* p140 = last_address;
PRINT_POINTER(scalloc(16,146););
printStats();
void* p141 = last_address;
PRINT_POINTER(scalloc(232,11););
printStats();
void* p142 = last_address;
PRINT_POINTER(smalloc(85););
printStats();
void* p143 = last_address;
PRINT_POINTER(smalloc(138););
printStats();
void* p144 = last_address;
PRINT_POINTER(scalloc(157,166););
printStats();
void* p145 = last_address;
DEBUG_PRINT(sfree(p97););
printStats();
DEBUG_PRINT(sfree(p109););
printStats();
PRINT_POINTER(scalloc(159,144););
printStats();
void* p146 = last_address;
PRINT_POINTER(scalloc(8,66););
printStats();
void* p147 = last_address;
PRINT_POINTER(scalloc(140,60););
printStats();
void* p148 = last_address;
PRINT_POINTER(scalloc(57,189););
printStats();
void* p149 = last_address;
PRINT_POINTER(srealloc(p55,99););
printStats();
void* p150 = last_address;
PRINT_POINTER(smalloc(27););
printStats();
void* p151 = last_address;
PRINT_POINTER(srealloc(p148,161););
printStats();
void* p152 = last_address;
PRINT_POINTER(smalloc(196););
printStats();
void* p153 = last_address;
PRINT_POINTER(scalloc(100,44););
printStats();
void* p154 = last_address;
DEBUG_PRINT(sfree(p130););
printStats();
DEBUG_PRINT(sfree(p71););
printStats();
PRINT_POINTER(smalloc(239););
printStats();
void* p155 = last_address;
PRINT_POINTER(scalloc(122,240););
printStats();
void* p156 = last_address;
PRINT_POINTER(smalloc(6););
printStats();
void* p157 = last_address;
PRINT_POINTER(smalloc(220););
printStats();
void* p158 = last_address;
PRINT_POINTER(scalloc(199,46););
printStats();
void* p159 = last_address;
PRINT_POINTER(srealloc(p136,163););
printStats();
void* p160 = last_address;
DEBUG_PRINT(sfree(p127););
printStats();
PRINT_POINTER(srealloc(p106,217););
printStats();
void* p161 = last_address;
PRINT_POINTER(srealloc(p126,81););
printStats();
void* p162 = last_address;
PRINT_POINTER(scalloc(69,115););
printStats();
void* p163 = last_address;
PRINT_POINTER(srealloc(p96,44););
printStats();
void* p164 = last_address;
PRINT_POINTER(smalloc(21););
printStats();
void* p165 = last_address;
PRINT_POINTER(srealloc(p118,89););
printStats();
void* p166 = last_address;
PRINT_POINTER(smalloc(108););
printStats();
void* p167 = last_address;
DEBUG_PRINT(sfree(p92););
printStats();
PRINT_POINTER(srealloc(p167,93););
printStats();
void* p168 = last_address;
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(scalloc(37,114););
printStats();
void* p169 = last_address;
PRINT_POINTER(scalloc(25,175););
printStats();
void* p170 = last_address;
PRINT_POINTER(srealloc(p139,101););
printStats();
void* p171 = last_address;
PRINT_POINTER(scalloc(20,155););
printStats();
void* p172 = last_address;
PRINT_POINTER(scalloc(158,229););
printStats();
void* p173 = last_address;
PRINT_POINTER(smalloc(125););
printStats();
void* p174 = last_address;
PRINT_POINTER(scalloc(185,226););
printStats();
void* p175 = last_address;
PRINT_POINTER(srealloc(p99,52););
printStats();
void* p176 = last_address;
PRINT_POINTER(srealloc(p119,115););
printStats();
void* p177 = last_address;
PRINT_POINTER(smalloc(225););
printStats();
void* p178 = last_address;
PRINT_POINTER(scalloc(245,96););
printStats();
void* p179 = last_address;
PRINT_POINTER(scalloc(152,82););
printStats();
void* p180 = last_address;
PRINT_POINTER(smalloc(70););
printStats();
void* p181 = last_address;
DEBUG_PRINT(sfree(p67););
printStats();
PRINT_POINTER(srealloc(p146,139););
printStats();
void* p182 = last_address;
PRINT_POINTER(srealloc(p156,72););
printStats();
void* p183 = last_address;
PRINT_POINTER(scalloc(183,190););
printStats();
void* p184 = last_address;
DEBUG_PRINT(sfree(p181););
printStats();
PRINT_POINTER(smalloc(14););
printStats();
void* p185 = last_address;
PRINT_POINTER(srealloc(p153,16););
printStats();
void* p186 = last_address;
PRINT_POINTER(srealloc(p29,235););
printStats();
void* p187 = last_address;
PRINT_POINTER(srealloc(p180,159););
printStats();
void* p188 = last_address;
PRINT_POINTER(scalloc(179,69););
printStats();
void* p189 = last_address;
PRINT_POINTER(scalloc(228,146););
printStats();
void* p190 = last_address;
PRINT_POINTER(smalloc(32););
printStats();
void* p191 = last_address;
PRINT_POINTER(srealloc(p158,99););
printStats();
void* p192 = last_address;
PRINT_POINTER(scalloc(221,39););
printStats();
void* p193 = last_address;
PRINT_POINTER(scalloc(10,143););
printStats();
void* p194 = last_address;
DEBUG_PRINT(sfree(p128););
printStats();
PRINT_POINTER(srealloc(p166,104););
printStats();
void* p195 = last_address;
DEBUG_PRINT(sfree(p111););
printStats();
DEBUG_PRINT(sfree(p185););
printStats();
DEBUG_PRINT(sfree(p150););
printStats();
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(scalloc(24,60););
printStats();
void* p196 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
DEBUG_PRINT(sfree(p125););
printStats();
PRINT_POINTER(scalloc(94,196););
printStats();
void* p197 = last_address;
}
