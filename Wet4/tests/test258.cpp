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
                        PRINT_POINTER(smalloc(162););
printStats();
void* p0 = last_address;
PRINT_POINTER(srealloc(p0,153););
printStats();
void* p1 = last_address;
PRINT_POINTER(smalloc(174););
printStats();
void* p2 = last_address;
PRINT_POINTER(scalloc(166,203););
printStats();
void* p3 = last_address;
PRINT_POINTER(scalloc(27,43););
printStats();
void* p4 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(srealloc(p1,119););
printStats();
void* p5 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
PRINT_POINTER(scalloc(12,107););
printStats();
void* p6 = last_address;
PRINT_POINTER(scalloc(248,13););
printStats();
void* p7 = last_address;
PRINT_POINTER(smalloc(148););
printStats();
void* p8 = last_address;
PRINT_POINTER(srealloc(p8,188););
printStats();
void* p9 = last_address;
PRINT_POINTER(smalloc(138););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p5,57););
printStats();
void* p11 = last_address;
DEBUG_PRINT(sfree(p11););
printStats();
PRINT_POINTER(scalloc(43,77););
printStats();
void* p12 = last_address;
DEBUG_PRINT(sfree(p2););
printStats();
PRINT_POINTER(smalloc(42););
printStats();
void* p13 = last_address;
PRINT_POINTER(scalloc(136,136););
printStats();
void* p14 = last_address;
DEBUG_PRINT(sfree(p13););
printStats();
PRINT_POINTER(scalloc(60,169););
printStats();
void* p15 = last_address;
DEBUG_PRINT(sfree(p12););
printStats();
PRINT_POINTER(scalloc(55,83););
printStats();
void* p16 = last_address;
DEBUG_PRINT(sfree(p10););
printStats();
PRINT_POINTER(smalloc(25););
printStats();
void* p17 = last_address;
DEBUG_PRINT(sfree(p16););
printStats();
PRINT_POINTER(smalloc(75););
printStats();
void* p18 = last_address;
PRINT_POINTER(srealloc(p14,141););
printStats();
void* p19 = last_address;
PRINT_POINTER(srealloc(p18,117););
printStats();
void* p20 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p21 = last_address;
PRINT_POINTER(scalloc(155,4););
printStats();
void* p22 = last_address;
PRINT_POINTER(scalloc(33,140););
printStats();
void* p23 = last_address;
PRINT_POINTER(srealloc(p20,210););
printStats();
void* p24 = last_address;
PRINT_POINTER(srealloc(p21,128););
printStats();
void* p25 = last_address;
PRINT_POINTER(scalloc(189,246););
printStats();
void* p26 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(srealloc(p7,208););
printStats();
void* p27 = last_address;
PRINT_POINTER(smalloc(51););
printStats();
void* p28 = last_address;
DEBUG_PRINT(sfree(p19););
printStats();
PRINT_POINTER(smalloc(217););
printStats();
void* p29 = last_address;
DEBUG_PRINT(sfree(p29););
printStats();
DEBUG_PRINT(sfree(p9););
printStats();
PRINT_POINTER(smalloc(204););
printStats();
void* p30 = last_address;
PRINT_POINTER(smalloc(10););
printStats();
void* p31 = last_address;
PRINT_POINTER(scalloc(1,99););
printStats();
void* p32 = last_address;
DEBUG_PRINT(sfree(p22););
printStats();
PRINT_POINTER(scalloc(14,91););
printStats();
void* p33 = last_address;
PRINT_POINTER(scalloc(61,24););
printStats();
void* p34 = last_address;
PRINT_POINTER(srealloc(p34,200););
printStats();
void* p35 = last_address;
PRINT_POINTER(srealloc(p31,161););
printStats();
void* p36 = last_address;
PRINT_POINTER(smalloc(113););
printStats();
void* p37 = last_address;
PRINT_POINTER(smalloc(118););
printStats();
void* p38 = last_address;
PRINT_POINTER(smalloc(173););
printStats();
void* p39 = last_address;
PRINT_POINTER(srealloc(p25,66););
printStats();
void* p40 = last_address;
PRINT_POINTER(srealloc(p32,167););
printStats();
void* p41 = last_address;
PRINT_POINTER(srealloc(p33,204););
printStats();
void* p42 = last_address;
PRINT_POINTER(scalloc(82,74););
printStats();
void* p43 = last_address;
DEBUG_PRINT(sfree(p28););
printStats();
PRINT_POINTER(smalloc(107););
printStats();
void* p44 = last_address;
PRINT_POINTER(srealloc(p41,198););
printStats();
void* p45 = last_address;
DEBUG_PRINT(sfree(p39););
printStats();
PRINT_POINTER(smalloc(123););
printStats();
void* p46 = last_address;
DEBUG_PRINT(sfree(p17););
printStats();
PRINT_POINTER(scalloc(54,111););
printStats();
void* p47 = last_address;
PRINT_POINTER(smalloc(91););
printStats();
void* p48 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
PRINT_POINTER(scalloc(78,169););
printStats();
void* p49 = last_address;
PRINT_POINTER(srealloc(p48,145););
printStats();
void* p50 = last_address;
PRINT_POINTER(srealloc(p44,126););
printStats();
void* p51 = last_address;
PRINT_POINTER(srealloc(p30,48););
printStats();
void* p52 = last_address;
PRINT_POINTER(srealloc(p42,147););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(132,166););
printStats();
void* p54 = last_address;
PRINT_POINTER(srealloc(p43,169););
printStats();
void* p55 = last_address;
PRINT_POINTER(smalloc(2););
printStats();
void* p56 = last_address;
PRINT_POINTER(srealloc(p52,80););
printStats();
void* p57 = last_address;
PRINT_POINTER(srealloc(p24,113););
printStats();
void* p58 = last_address;
PRINT_POINTER(scalloc(130,113););
printStats();
void* p59 = last_address;
PRINT_POINTER(scalloc(190,243););
printStats();
void* p60 = last_address;
PRINT_POINTER(srealloc(p55,125););
printStats();
void* p61 = last_address;
PRINT_POINTER(scalloc(42,58););
printStats();
void* p62 = last_address;
PRINT_POINTER(smalloc(110););
printStats();
void* p63 = last_address;
DEBUG_PRINT(sfree(p62););
printStats();
PRINT_POINTER(scalloc(86,142););
printStats();
void* p64 = last_address;
DEBUG_PRINT(sfree(p60););
printStats();
DEBUG_PRINT(sfree(p45););
printStats();
PRINT_POINTER(srealloc(p47,223););
printStats();
void* p65 = last_address;
PRINT_POINTER(smalloc(75););
printStats();
void* p66 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p67 = last_address;
PRINT_POINTER(srealloc(p67,109););
printStats();
void* p68 = last_address;
PRINT_POINTER(smalloc(50););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p70 = last_address;
DEBUG_PRINT(sfree(p65););
printStats();
PRINT_POINTER(srealloc(p69,155););
printStats();
void* p71 = last_address;
PRINT_POINTER(smalloc(43););
printStats();
void* p72 = last_address;
PRINT_POINTER(srealloc(p37,143););
printStats();
void* p73 = last_address;
PRINT_POINTER(srealloc(p15,150););
printStats();
void* p74 = last_address;
PRINT_POINTER(scalloc(244,10););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(146,97););
printStats();
void* p76 = last_address;
PRINT_POINTER(smalloc(198););
printStats();
void* p77 = last_address;
PRINT_POINTER(smalloc(216););
printStats();
void* p78 = last_address;
DEBUG_PRINT(sfree(p53););
printStats();
PRINT_POINTER(srealloc(p68,220););
printStats();
void* p79 = last_address;
PRINT_POINTER(smalloc(199););
printStats();
void* p80 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
DEBUG_PRINT(sfree(p27););
printStats();
PRINT_POINTER(srealloc(p63,10););
printStats();
void* p81 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
DEBUG_PRINT(sfree(p46););
printStats();
PRINT_POINTER(smalloc(48););
printStats();
void* p82 = last_address;
PRINT_POINTER(scalloc(101,68););
printStats();
void* p83 = last_address;
PRINT_POINTER(srealloc(p58,158););
printStats();
void* p84 = last_address;
DEBUG_PRINT(sfree(p38););
printStats();
PRINT_POINTER(srealloc(p80,5););
printStats();
void* p85 = last_address;
PRINT_POINTER(smalloc(185););
printStats();
void* p86 = last_address;
DEBUG_PRINT(sfree(p77););
printStats();
PRINT_POINTER(srealloc(p26,88););
printStats();
void* p87 = last_address;
PRINT_POINTER(scalloc(83,111););
printStats();
void* p88 = last_address;
PRINT_POINTER(srealloc(p72,57););
printStats();
void* p89 = last_address;
PRINT_POINTER(srealloc(p88,116););
printStats();
void* p90 = last_address;
PRINT_POINTER(smalloc(96););
printStats();
void* p91 = last_address;
PRINT_POINTER(scalloc(126,243););
printStats();
void* p92 = last_address;
PRINT_POINTER(srealloc(p86,136););
printStats();
void* p93 = last_address;
PRINT_POINTER(scalloc(22,5););
printStats();
void* p94 = last_address;
PRINT_POINTER(scalloc(61,70););
printStats();
void* p95 = last_address;
PRINT_POINTER(srealloc(p57,106););
printStats();
void* p96 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
DEBUG_PRINT(sfree(p79););
printStats();
PRINT_POINTER(scalloc(85,49););
printStats();
void* p97 = last_address;
PRINT_POINTER(srealloc(p94,197););
printStats();
void* p98 = last_address;
PRINT_POINTER(srealloc(p83,227););
printStats();
void* p99 = last_address;
PRINT_POINTER(smalloc(11););
printStats();
void* p100 = last_address;
PRINT_POINTER(scalloc(41,230););
printStats();
void* p101 = last_address;
DEBUG_PRINT(sfree(p71););
printStats();
PRINT_POINTER(scalloc(11,89););
printStats();
void* p102 = last_address;
DEBUG_PRINT(sfree(p78););
printStats();
PRINT_POINTER(scalloc(116,6););
printStats();
void* p103 = last_address;
PRINT_POINTER(smalloc(11););
printStats();
void* p104 = last_address;
PRINT_POINTER(smalloc(200););
printStats();
void* p105 = last_address;
PRINT_POINTER(srealloc(p51,113););
printStats();
void* p106 = last_address;
PRINT_POINTER(scalloc(35,231););
printStats();
void* p107 = last_address;
PRINT_POINTER(srealloc(p35,35););
printStats();
void* p108 = last_address;
DEBUG_PRINT(sfree(p56););
printStats();
DEBUG_PRINT(sfree(p59););
printStats();
DEBUG_PRINT(sfree(p91););
printStats();
PRINT_POINTER(smalloc(244););
printStats();
void* p109 = last_address;
DEBUG_PRINT(sfree(p61););
printStats();
PRINT_POINTER(scalloc(218,222););
printStats();
void* p110 = last_address;
PRINT_POINTER(smalloc(183););
printStats();
void* p111 = last_address;
PRINT_POINTER(srealloc(p107,29););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(218););
printStats();
void* p113 = last_address;
PRINT_POINTER(smalloc(128););
printStats();
void* p114 = last_address;
DEBUG_PRINT(sfree(p104););
printStats();
DEBUG_PRINT(sfree(p66););
printStats();
DEBUG_PRINT(sfree(p98););
printStats();
PRINT_POINTER(srealloc(p81,60););
printStats();
void* p115 = last_address;
PRINT_POINTER(scalloc(181,43););
printStats();
void* p116 = last_address;
PRINT_POINTER(scalloc(240,119););
printStats();
void* p117 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
DEBUG_PRINT(sfree(p92););
printStats();
PRINT_POINTER(smalloc(15););
printStats();
void* p118 = last_address;
DEBUG_PRINT(sfree(p108););
printStats();
DEBUG_PRINT(sfree(p103););
printStats();
DEBUG_PRINT(sfree(p109););
printStats();
PRINT_POINTER(srealloc(p82,202););
printStats();
void* p119 = last_address;
PRINT_POINTER(srealloc(p74,241););
printStats();
void* p120 = last_address;
PRINT_POINTER(scalloc(58,36););
printStats();
void* p121 = last_address;
PRINT_POINTER(smalloc(211););
printStats();
void* p122 = last_address;
PRINT_POINTER(srealloc(p99,93););
printStats();
void* p123 = last_address;
PRINT_POINTER(srealloc(p118,24););
printStats();
void* p124 = last_address;
PRINT_POINTER(smalloc(179););
printStats();
void* p125 = last_address;
DEBUG_PRINT(sfree(p116););
printStats();
PRINT_POINTER(smalloc(5););
printStats();
void* p126 = last_address;
PRINT_POINTER(srealloc(p87,114););
printStats();
void* p127 = last_address;
PRINT_POINTER(smalloc(112););
printStats();
void* p128 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
PRINT_POINTER(smalloc(117););
printStats();
void* p129 = last_address;
DEBUG_PRINT(sfree(p125););
printStats();
DEBUG_PRINT(sfree(p129););
printStats();
PRINT_POINTER(scalloc(164,139););
printStats();
void* p130 = last_address;
PRINT_POINTER(smalloc(217););
printStats();
void* p131 = last_address;
PRINT_POINTER(srealloc(p95,183););
printStats();
void* p132 = last_address;
PRINT_POINTER(srealloc(p73,239););
printStats();
void* p133 = last_address;
PRINT_POINTER(srealloc(p102,31););
printStats();
void* p134 = last_address;
PRINT_POINTER(srealloc(p126,226););
printStats();
void* p135 = last_address;
PRINT_POINTER(smalloc(237););
printStats();
void* p136 = last_address;
PRINT_POINTER(srealloc(p90,44););
printStats();
void* p137 = last_address;
PRINT_POINTER(scalloc(178,210););
printStats();
void* p138 = last_address;
PRINT_POINTER(smalloc(88););
printStats();
void* p139 = last_address;
PRINT_POINTER(smalloc(26););
printStats();
void* p140 = last_address;
PRINT_POINTER(scalloc(198,147););
printStats();
void* p141 = last_address;
PRINT_POINTER(srealloc(p130,102););
printStats();
void* p142 = last_address;
PRINT_POINTER(scalloc(147,127););
printStats();
void* p143 = last_address;
DEBUG_PRINT(sfree(p64););
printStats();
DEBUG_PRINT(sfree(p105););
printStats();
DEBUG_PRINT(sfree(p93););
printStats();
PRINT_POINTER(scalloc(113,22););
printStats();
void* p144 = last_address;
DEBUG_PRINT(sfree(p117););
printStats();
PRINT_POINTER(smalloc(141););
printStats();
void* p145 = last_address;
PRINT_POINTER(srealloc(p142,88););
printStats();
void* p146 = last_address;
DEBUG_PRINT(sfree(p106););
printStats();
PRINT_POINTER(scalloc(210,91););
printStats();
void* p147 = last_address;
DEBUG_PRINT(sfree(p115););
printStats();
PRINT_POINTER(smalloc(157););
printStats();
void* p148 = last_address;
PRINT_POINTER(scalloc(76,92););
printStats();
void* p149 = last_address;
PRINT_POINTER(smalloc(161););
printStats();
void* p150 = last_address;
PRINT_POINTER(srealloc(p89,48););
printStats();
void* p151 = last_address;
PRINT_POINTER(scalloc(65,227););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p150,45););
printStats();
void* p153 = last_address;
PRINT_POINTER(smalloc(53););
printStats();
void* p154 = last_address;
PRINT_POINTER(scalloc(231,149););
printStats();
void* p155 = last_address;
PRINT_POINTER(srealloc(p149,203););
printStats();
void* p156 = last_address;
PRINT_POINTER(smalloc(167););
printStats();
void* p157 = last_address;
PRINT_POINTER(smalloc(240););
printStats();
void* p158 = last_address;
PRINT_POINTER(smalloc(26););
printStats();
void* p159 = last_address;
PRINT_POINTER(srealloc(p100,14););
printStats();
void* p160 = last_address;
PRINT_POINTER(srealloc(p143,164););
printStats();
void* p161 = last_address;
PRINT_POINTER(srealloc(p156,32););
printStats();
void* p162 = last_address;
PRINT_POINTER(scalloc(110,8););
printStats();
void* p163 = last_address;
PRINT_POINTER(scalloc(9,41););
printStats();
void* p164 = last_address;
PRINT_POINTER(scalloc(3,185););
printStats();
void* p165 = last_address;
DEBUG_PRINT(sfree(p76););
printStats();
PRINT_POINTER(smalloc(157););
printStats();
void* p166 = last_address;
DEBUG_PRINT(sfree(p163););
printStats();
DEBUG_PRINT(sfree(p139););
printStats();
DEBUG_PRINT(sfree(p132););
printStats();
PRINT_POINTER(smalloc(174););
printStats();
void* p167 = last_address;
PRINT_POINTER(smalloc(170););
printStats();
void* p168 = last_address;
PRINT_POINTER(srealloc(p75,111););
printStats();
void* p169 = last_address;
PRINT_POINTER(scalloc(50,60););
printStats();
void* p170 = last_address;
DEBUG_PRINT(sfree(p122););
printStats();
PRINT_POINTER(scalloc(65,20););
printStats();
void* p171 = last_address;
PRINT_POINTER(smalloc(121););
printStats();
void* p172 = last_address;
PRINT_POINTER(srealloc(p133,209););
printStats();
void* p173 = last_address;
PRINT_POINTER(srealloc(p153,164););
printStats();
void* p174 = last_address;
PRINT_POINTER(scalloc(40,21););
printStats();
void* p175 = last_address;
DEBUG_PRINT(sfree(p110););
printStats();
PRINT_POINTER(smalloc(32););
printStats();
void* p176 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
DEBUG_PRINT(sfree(p127););
printStats();
PRINT_POINTER(srealloc(p140,71););
printStats();
void* p177 = last_address;
DEBUG_PRINT(sfree(p146););
printStats();
PRINT_POINTER(smalloc(147););
printStats();
void* p178 = last_address;
DEBUG_PRINT(sfree(p123););
printStats();
DEBUG_PRINT(sfree(p169););
printStats();
PRINT_POINTER(srealloc(p158,233););
printStats();
void* p179 = last_address;
PRINT_POINTER(srealloc(p173,110););
printStats();
void* p180 = last_address;
PRINT_POINTER(smalloc(49););
printStats();
void* p181 = last_address;
DEBUG_PRINT(sfree(p171););
printStats();
PRINT_POINTER(srealloc(p84,146););
printStats();
void* p182 = last_address;
PRINT_POINTER(srealloc(p148,34););
printStats();
void* p183 = last_address;
PRINT_POINTER(scalloc(19,17););
printStats();
void* p184 = last_address;
PRINT_POINTER(scalloc(206,96););
printStats();
void* p185 = last_address;
PRINT_POINTER(smalloc(151););
printStats();
void* p186 = last_address;
PRINT_POINTER(srealloc(p177,181););
printStats();
void* p187 = last_address;
PRINT_POINTER(smalloc(29););
printStats();
void* p188 = last_address;
PRINT_POINTER(scalloc(181,103););
printStats();
void* p189 = last_address;
DEBUG_PRINT(sfree(p165););
printStats();
PRINT_POINTER(srealloc(p152,243););
printStats();
void* p190 = last_address;
PRINT_POINTER(srealloc(p135,172););
printStats();
void* p191 = last_address;
PRINT_POINTER(srealloc(p187,247););
printStats();
void* p192 = last_address;
PRINT_POINTER(scalloc(23,96););
printStats();
void* p193 = last_address;
PRINT_POINTER(srealloc(p128,249););
printStats();
void* p194 = last_address;
PRINT_POINTER(smalloc(64););
printStats();
void* p195 = last_address;
DEBUG_PRINT(sfree(p120););
printStats();
PRINT_POINTER(scalloc(244,30););
printStats();
void* p196 = last_address;
PRINT_POINTER(scalloc(82,224););
printStats();
void* p197 = last_address;
PRINT_POINTER(smalloc(178););
printStats();
void* p198 = last_address;
PRINT_POINTER(smalloc(19););
printStats();
void* p199 = last_address;
PRINT_POINTER(srealloc(p111,38););
printStats();
void* p200 = last_address;
PRINT_POINTER(smalloc(243););
printStats();
void* p201 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(smalloc(190););
printStats();
void* p202 = last_address;
DEBUG_PRINT(sfree(p159););
printStats();
PRINT_POINTER(srealloc(p198,98););
printStats();
void* p203 = last_address;
PRINT_POINTER(srealloc(p170,65););
printStats();
void* p204 = last_address;
PRINT_POINTER(smalloc(123););
printStats();
void* p205 = last_address;
}
