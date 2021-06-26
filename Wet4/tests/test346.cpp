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
                        PRINT_POINTER(smalloc(80););
printStats();
void* p0 = last_address;
DEBUG_PRINT(sfree(p0););
printStats();
PRINT_POINTER(scalloc(87,229););
printStats();
void* p1 = last_address;
PRINT_POINTER(srealloc(p1,221););
printStats();
void* p2 = last_address;
PRINT_POINTER(scalloc(17,227););
printStats();
void* p3 = last_address;
PRINT_POINTER(smalloc(165););
printStats();
void* p4 = last_address;
PRINT_POINTER(srealloc(p2,137););
printStats();
void* p5 = last_address;
PRINT_POINTER(scalloc(242,169););
printStats();
void* p6 = last_address;
PRINT_POINTER(scalloc(154,206););
printStats();
void* p7 = last_address;
PRINT_POINTER(scalloc(78,103););
printStats();
void* p8 = last_address;
PRINT_POINTER(smalloc(53););
printStats();
void* p9 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(srealloc(p5,191););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p8,25););
printStats();
void* p11 = last_address;
PRINT_POINTER(scalloc(202,126););
printStats();
void* p12 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(smalloc(10););
printStats();
void* p13 = last_address;
PRINT_POINTER(srealloc(p7,59););
printStats();
void* p14 = last_address;
PRINT_POINTER(smalloc(38););
printStats();
void* p15 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
PRINT_POINTER(smalloc(125););
printStats();
void* p16 = last_address;
PRINT_POINTER(srealloc(p13,232););
printStats();
void* p17 = last_address;
PRINT_POINTER(srealloc(p9,129););
printStats();
void* p18 = last_address;
PRINT_POINTER(srealloc(p18,186););
printStats();
void* p19 = last_address;
PRINT_POINTER(scalloc(105,158););
printStats();
void* p20 = last_address;
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(smalloc(119););
printStats();
void* p21 = last_address;
PRINT_POINTER(smalloc(131););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p19););
printStats();
DEBUG_PRINT(sfree(p10););
printStats();
PRINT_POINTER(scalloc(100,143););
printStats();
void* p23 = last_address;
PRINT_POINTER(scalloc(74,19););
printStats();
void* p24 = last_address;
PRINT_POINTER(smalloc(3););
printStats();
void* p25 = last_address;
PRINT_POINTER(smalloc(162););
printStats();
void* p26 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(48,151););
printStats();
void* p28 = last_address;
DEBUG_PRINT(sfree(p28););
printStats();
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(srealloc(p14,186););
printStats();
void* p29 = last_address;
PRINT_POINTER(srealloc(p21,168););
printStats();
void* p30 = last_address;
PRINT_POINTER(scalloc(23,179););
printStats();
void* p31 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(scalloc(94,160););
printStats();
void* p32 = last_address;
PRINT_POINTER(srealloc(p12,132););
printStats();
void* p33 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p34 = last_address;
PRINT_POINTER(smalloc(120););
printStats();
void* p35 = last_address;
PRINT_POINTER(srealloc(p31,61););
printStats();
void* p36 = last_address;
DEBUG_PRINT(sfree(p27););
printStats();
DEBUG_PRINT(sfree(p25););
printStats();
DEBUG_PRINT(sfree(p35););
printStats();
PRINT_POINTER(scalloc(132,6););
printStats();
void* p37 = last_address;
PRINT_POINTER(scalloc(71,198););
printStats();
void* p38 = last_address;
PRINT_POINTER(srealloc(p36,41););
printStats();
void* p39 = last_address;
PRINT_POINTER(srealloc(p11,245););
printStats();
void* p40 = last_address;
PRINT_POINTER(srealloc(p16,201););
printStats();
void* p41 = last_address;
PRINT_POINTER(scalloc(188,98););
printStats();
void* p42 = last_address;
DEBUG_PRINT(sfree(p17););
printStats();
PRINT_POINTER(smalloc(166););
printStats();
void* p43 = last_address;
PRINT_POINTER(smalloc(137););
printStats();
void* p44 = last_address;
DEBUG_PRINT(sfree(p42););
printStats();
PRINT_POINTER(scalloc(125,207););
printStats();
void* p45 = last_address;
DEBUG_PRINT(sfree(p43););
printStats();
DEBUG_PRINT(sfree(p26););
printStats();
DEBUG_PRINT(sfree(p38););
printStats();
DEBUG_PRINT(sfree(p30););
printStats();
DEBUG_PRINT(sfree(p33););
printStats();
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(srealloc(p45,69););
printStats();
void* p46 = last_address;
PRINT_POINTER(smalloc(125););
printStats();
void* p47 = last_address;
PRINT_POINTER(smalloc(178););
printStats();
void* p48 = last_address;
PRINT_POINTER(scalloc(110,186););
printStats();
void* p49 = last_address;
PRINT_POINTER(scalloc(160,220););
printStats();
void* p50 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
PRINT_POINTER(scalloc(119,177););
printStats();
void* p51 = last_address;
PRINT_POINTER(scalloc(77,48););
printStats();
void* p52 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
DEBUG_PRINT(sfree(p24););
printStats();
DEBUG_PRINT(sfree(p48););
printStats();
PRINT_POINTER(scalloc(223,8););
printStats();
void* p53 = last_address;
DEBUG_PRINT(sfree(p22););
printStats();
DEBUG_PRINT(sfree(p49););
printStats();
PRINT_POINTER(scalloc(175,215););
printStats();
void* p54 = last_address;
PRINT_POINTER(scalloc(67,162););
printStats();
void* p55 = last_address;
DEBUG_PRINT(sfree(p29););
printStats();
PRINT_POINTER(scalloc(41,87););
printStats();
void* p56 = last_address;
PRINT_POINTER(smalloc(66););
printStats();
void* p57 = last_address;
PRINT_POINTER(smalloc(237););
printStats();
void* p58 = last_address;
PRINT_POINTER(srealloc(p56,46););
printStats();
void* p59 = last_address;
DEBUG_PRINT(sfree(p52););
printStats();
PRINT_POINTER(smalloc(190););
printStats();
void* p60 = last_address;
PRINT_POINTER(srealloc(p51,22););
printStats();
void* p61 = last_address;
PRINT_POINTER(srealloc(p54,84););
printStats();
void* p62 = last_address;
PRINT_POINTER(srealloc(p50,221););
printStats();
void* p63 = last_address;
PRINT_POINTER(scalloc(190,62););
printStats();
void* p64 = last_address;
PRINT_POINTER(scalloc(247,132););
printStats();
void* p65 = last_address;
PRINT_POINTER(smalloc(110););
printStats();
void* p66 = last_address;
DEBUG_PRINT(sfree(p58););
printStats();
PRINT_POINTER(smalloc(144););
printStats();
void* p67 = last_address;
PRINT_POINTER(smalloc(103););
printStats();
void* p68 = last_address;
DEBUG_PRINT(sfree(p60););
printStats();
PRINT_POINTER(srealloc(p55,94););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(167););
printStats();
void* p70 = last_address;
PRINT_POINTER(smalloc(73););
printStats();
void* p71 = last_address;
PRINT_POINTER(scalloc(145,247););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(60,150););
printStats();
void* p73 = last_address;
PRINT_POINTER(smalloc(107););
printStats();
void* p74 = last_address;
PRINT_POINTER(srealloc(p74,69););
printStats();
void* p75 = last_address;
DEBUG_PRINT(sfree(p62););
printStats();
PRINT_POINTER(smalloc(149););
printStats();
void* p76 = last_address;
DEBUG_PRINT(sfree(p76););
printStats();
PRINT_POINTER(srealloc(p69,39););
printStats();
void* p77 = last_address;
PRINT_POINTER(smalloc(27););
printStats();
void* p78 = last_address;
PRINT_POINTER(smalloc(154););
printStats();
void* p79 = last_address;
PRINT_POINTER(smalloc(47););
printStats();
void* p80 = last_address;
PRINT_POINTER(smalloc(237););
printStats();
void* p81 = last_address;
DEBUG_PRINT(sfree(p44););
printStats();
PRINT_POINTER(smalloc(53););
printStats();
void* p82 = last_address;
PRINT_POINTER(scalloc(116,215););
printStats();
void* p83 = last_address;
DEBUG_PRINT(sfree(p37););
printStats();
PRINT_POINTER(smalloc(225););
printStats();
void* p84 = last_address;
DEBUG_PRINT(sfree(p75););
printStats();
PRINT_POINTER(smalloc(152););
printStats();
void* p85 = last_address;
PRINT_POINTER(srealloc(p80,123););
printStats();
void* p86 = last_address;
PRINT_POINTER(scalloc(138,1););
printStats();
void* p87 = last_address;
PRINT_POINTER(scalloc(97,135););
printStats();
void* p88 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
PRINT_POINTER(smalloc(69););
printStats();
void* p89 = last_address;
PRINT_POINTER(scalloc(92,63););
printStats();
void* p90 = last_address;
PRINT_POINTER(smalloc(125););
printStats();
void* p91 = last_address;
PRINT_POINTER(smalloc(130););
printStats();
void* p92 = last_address;
PRINT_POINTER(scalloc(198,15););
printStats();
void* p93 = last_address;
PRINT_POINTER(srealloc(p39,38););
printStats();
void* p94 = last_address;
PRINT_POINTER(srealloc(p93,201););
printStats();
void* p95 = last_address;
DEBUG_PRINT(sfree(p91););
printStats();
PRINT_POINTER(scalloc(233,125););
printStats();
void* p96 = last_address;
PRINT_POINTER(srealloc(p88,150););
printStats();
void* p97 = last_address;
DEBUG_PRINT(sfree(p77););
printStats();
DEBUG_PRINT(sfree(p71););
printStats();
DEBUG_PRINT(sfree(p83););
printStats();
PRINT_POINTER(scalloc(93,54););
printStats();
void* p98 = last_address;
PRINT_POINTER(srealloc(p72,157););
printStats();
void* p99 = last_address;
DEBUG_PRINT(sfree(p95););
printStats();
PRINT_POINTER(scalloc(131,148););
printStats();
void* p100 = last_address;
PRINT_POINTER(scalloc(200,187););
printStats();
void* p101 = last_address;
DEBUG_PRINT(sfree(p70););
printStats();
PRINT_POINTER(scalloc(68,127););
printStats();
void* p102 = last_address;
PRINT_POINTER(srealloc(p94,4););
printStats();
void* p103 = last_address;
PRINT_POINTER(scalloc(79,194););
printStats();
void* p104 = last_address;
DEBUG_PRINT(sfree(p84););
printStats();
PRINT_POINTER(srealloc(p65,239););
printStats();
void* p105 = last_address;
PRINT_POINTER(smalloc(19););
printStats();
void* p106 = last_address;
PRINT_POINTER(srealloc(p57,192););
printStats();
void* p107 = last_address;
PRINT_POINTER(smalloc(195););
printStats();
void* p108 = last_address;
PRINT_POINTER(srealloc(p66,81););
printStats();
void* p109 = last_address;
DEBUG_PRINT(sfree(p107););
printStats();
PRINT_POINTER(srealloc(p108,84););
printStats();
void* p110 = last_address;
PRINT_POINTER(smalloc(197););
printStats();
void* p111 = last_address;
PRINT_POINTER(smalloc(177););
printStats();
void* p112 = last_address;
PRINT_POINTER(scalloc(35,166););
printStats();
void* p113 = last_address;
DEBUG_PRINT(sfree(p63););
printStats();
DEBUG_PRINT(sfree(p73););
printStats();
DEBUG_PRINT(sfree(p110););
printStats();
DEBUG_PRINT(sfree(p100););
printStats();
PRINT_POINTER(smalloc(69););
printStats();
void* p114 = last_address;
PRINT_POINTER(srealloc(p82,80););
printStats();
void* p115 = last_address;
PRINT_POINTER(srealloc(p102,163););
printStats();
void* p116 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
PRINT_POINTER(srealloc(p111,4););
printStats();
void* p117 = last_address;
PRINT_POINTER(smalloc(176););
printStats();
void* p118 = last_address;
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(srealloc(p118,132););
printStats();
void* p119 = last_address;
PRINT_POINTER(smalloc(127););
printStats();
void* p120 = last_address;
DEBUG_PRINT(sfree(p120););
printStats();
DEBUG_PRINT(sfree(p97););
printStats();
PRINT_POINTER(smalloc(97););
printStats();
void* p121 = last_address;
PRINT_POINTER(scalloc(125,78););
printStats();
void* p122 = last_address;
DEBUG_PRINT(sfree(p113););
printStats();
PRINT_POINTER(srealloc(p68,149););
printStats();
void* p123 = last_address;
PRINT_POINTER(scalloc(47,158););
printStats();
void* p124 = last_address;
DEBUG_PRINT(sfree(p104););
printStats();
PRINT_POINTER(smalloc(18););
printStats();
void* p125 = last_address;
PRINT_POINTER(smalloc(167););
printStats();
void* p126 = last_address;
PRINT_POINTER(scalloc(162,188););
printStats();
void* p127 = last_address;
PRINT_POINTER(scalloc(5,204););
printStats();
void* p128 = last_address;
PRINT_POINTER(scalloc(230,68););
printStats();
void* p129 = last_address;
PRINT_POINTER(srealloc(p106,85););
printStats();
void* p130 = last_address;
PRINT_POINTER(srealloc(p112,196););
printStats();
void* p131 = last_address;
PRINT_POINTER(scalloc(69,96););
printStats();
void* p132 = last_address;
PRINT_POINTER(scalloc(87,191););
printStats();
void* p133 = last_address;
PRINT_POINTER(smalloc(107););
printStats();
void* p134 = last_address;
DEBUG_PRINT(sfree(p59););
printStats();
PRINT_POINTER(scalloc(65,219););
printStats();
void* p135 = last_address;
PRINT_POINTER(smalloc(237););
printStats();
void* p136 = last_address;
DEBUG_PRINT(sfree(p103););
printStats();
DEBUG_PRINT(sfree(p90););
printStats();
PRINT_POINTER(scalloc(222,97););
printStats();
void* p137 = last_address;
DEBUG_PRINT(sfree(p81););
printStats();
PRINT_POINTER(srealloc(p134,240););
printStats();
void* p138 = last_address;
PRINT_POINTER(scalloc(234,175););
printStats();
void* p139 = last_address;
PRINT_POINTER(scalloc(199,155););
printStats();
void* p140 = last_address;
DEBUG_PRINT(sfree(p115););
printStats();
PRINT_POINTER(scalloc(187,149););
printStats();
void* p141 = last_address;
PRINT_POINTER(srealloc(p138,62););
printStats();
void* p142 = last_address;
PRINT_POINTER(smalloc(207););
printStats();
void* p143 = last_address;
PRINT_POINTER(scalloc(135,139););
printStats();
void* p144 = last_address;
PRINT_POINTER(srealloc(p132,80););
printStats();
void* p145 = last_address;
DEBUG_PRINT(sfree(p64););
printStats();
PRINT_POINTER(scalloc(66,17););
printStats();
void* p146 = last_address;
DEBUG_PRINT(sfree(p146););
printStats();
PRINT_POINTER(scalloc(34,198););
printStats();
void* p147 = last_address;
PRINT_POINTER(scalloc(200,142););
printStats();
void* p148 = last_address;
PRINT_POINTER(scalloc(55,213););
printStats();
void* p149 = last_address;
PRINT_POINTER(srealloc(p129,7););
printStats();
void* p150 = last_address;
PRINT_POINTER(srealloc(p131,33););
printStats();
void* p151 = last_address;
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(scalloc(62,167););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p126,176););
printStats();
void* p153 = last_address;
PRINT_POINTER(smalloc(95););
printStats();
void* p154 = last_address;
PRINT_POINTER(smalloc(42););
printStats();
void* p155 = last_address;
PRINT_POINTER(smalloc(143););
printStats();
void* p156 = last_address;
DEBUG_PRINT(sfree(p128););
printStats();
PRINT_POINTER(srealloc(p154,117););
printStats();
void* p157 = last_address;
DEBUG_PRINT(sfree(p136););
printStats();
DEBUG_PRINT(sfree(p98););
printStats();
PRINT_POINTER(smalloc(170););
printStats();
void* p158 = last_address;
PRINT_POINTER(srealloc(p139,129););
printStats();
void* p159 = last_address;
DEBUG_PRINT(sfree(p156););
printStats();
PRINT_POINTER(scalloc(16,167););
printStats();
void* p160 = last_address;
PRINT_POINTER(srealloc(p109,62););
printStats();
void* p161 = last_address;
DEBUG_PRINT(sfree(p151););
printStats();
PRINT_POINTER(smalloc(105););
printStats();
void* p162 = last_address;
DEBUG_PRINT(sfree(p123););
printStats();
PRINT_POINTER(srealloc(p47,151););
printStats();
void* p163 = last_address;
PRINT_POINTER(scalloc(81,161););
printStats();
void* p164 = last_address;
PRINT_POINTER(smalloc(37););
printStats();
void* p165 = last_address;
PRINT_POINTER(smalloc(19););
printStats();
void* p166 = last_address;
PRINT_POINTER(smalloc(182););
printStats();
void* p167 = last_address;
PRINT_POINTER(srealloc(p41,236););
printStats();
void* p168 = last_address;
PRINT_POINTER(scalloc(141,235););
printStats();
void* p169 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
DEBUG_PRINT(sfree(p114););
printStats();
DEBUG_PRINT(sfree(p92););
printStats();
PRINT_POINTER(srealloc(p143,71););
printStats();
void* p170 = last_address;
PRINT_POINTER(srealloc(p153,182););
printStats();
void* p171 = last_address;
PRINT_POINTER(srealloc(p67,23););
printStats();
void* p172 = last_address;
PRINT_POINTER(smalloc(33););
printStats();
void* p173 = last_address;
PRINT_POINTER(smalloc(123););
printStats();
void* p174 = last_address;
PRINT_POINTER(scalloc(99,240););
printStats();
void* p175 = last_address;
PRINT_POINTER(scalloc(176,205););
printStats();
void* p176 = last_address;
PRINT_POINTER(scalloc(207,235););
printStats();
void* p177 = last_address;
PRINT_POINTER(smalloc(63););
printStats();
void* p178 = last_address;
PRINT_POINTER(scalloc(141,63););
printStats();
void* p179 = last_address;
PRINT_POINTER(scalloc(117,203););
printStats();
void* p180 = last_address;
PRINT_POINTER(srealloc(p145,43););
printStats();
void* p181 = last_address;
PRINT_POINTER(scalloc(225,199););
printStats();
void* p182 = last_address;
PRINT_POINTER(scalloc(121,120););
printStats();
void* p183 = last_address;
PRINT_POINTER(scalloc(89,46););
printStats();
void* p184 = last_address;
PRINT_POINTER(srealloc(p137,224););
printStats();
void* p185 = last_address;
DEBUG_PRINT(sfree(p174););
printStats();
PRINT_POINTER(scalloc(135,247););
printStats();
void* p186 = last_address;
PRINT_POINTER(srealloc(p116,97););
printStats();
void* p187 = last_address;
PRINT_POINTER(scalloc(75,140););
printStats();
void* p188 = last_address;
PRINT_POINTER(scalloc(8,63););
printStats();
void* p189 = last_address;
PRINT_POINTER(smalloc(119););
printStats();
void* p190 = last_address;
PRINT_POINTER(scalloc(144,69););
printStats();
void* p191 = last_address;
PRINT_POINTER(srealloc(p171,4););
printStats();
void* p192 = last_address;
PRINT_POINTER(smalloc(94););
printStats();
void* p193 = last_address;
PRINT_POINTER(srealloc(p167,247););
printStats();
void* p194 = last_address;
PRINT_POINTER(smalloc(115););
printStats();
void* p195 = last_address;
PRINT_POINTER(smalloc(161););
printStats();
void* p196 = last_address;
PRINT_POINTER(scalloc(194,89););
printStats();
void* p197 = last_address;
PRINT_POINTER(srealloc(p182,241););
printStats();
void* p198 = last_address;
PRINT_POINTER(srealloc(p160,68););
printStats();
void* p199 = last_address;
PRINT_POINTER(scalloc(16,177););
printStats();
void* p200 = last_address;
PRINT_POINTER(smalloc(84););
printStats();
void* p201 = last_address;
PRINT_POINTER(scalloc(81,58););
printStats();
void* p202 = last_address;
PRINT_POINTER(scalloc(220,230););
printStats();
void* p203 = last_address;
PRINT_POINTER(srealloc(p149,185););
printStats();
void* p204 = last_address;
PRINT_POINTER(smalloc(183););
printStats();
void* p205 = last_address;
DEBUG_PRINT(sfree(p199););
printStats();
DEBUG_PRINT(sfree(p155););
printStats();
PRINT_POINTER(srealloc(p200,231););
printStats();
void* p206 = last_address;
PRINT_POINTER(scalloc(164,63););
printStats();
void* p207 = last_address;
PRINT_POINTER(srealloc(p183,175););
printStats();
void* p208 = last_address;
PRINT_POINTER(scalloc(128,172););
printStats();
void* p209 = last_address;
PRINT_POINTER(smalloc(1););
printStats();
void* p210 = last_address;
PRINT_POINTER(smalloc(154););
printStats();
void* p211 = last_address;
PRINT_POINTER(scalloc(210,9););
printStats();
void* p212 = last_address;
PRINT_POINTER(smalloc(69););
printStats();
void* p213 = last_address;
DEBUG_PRINT(sfree(p202););
printStats();
PRINT_POINTER(srealloc(p121,8););
printStats();
void* p214 = last_address;
DEBUG_PRINT(sfree(p78););
printStats();
PRINT_POINTER(smalloc(204););
printStats();
void* p215 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
DEBUG_PRINT(sfree(p119););
printStats();
PRINT_POINTER(srealloc(p176,34););
printStats();
void* p216 = last_address;
PRINT_POINTER(scalloc(130,21););
printStats();
void* p217 = last_address;
DEBUG_PRINT(sfree(p189););
printStats();
PRINT_POINTER(srealloc(p86,91););
printStats();
void* p218 = last_address;
PRINT_POINTER(smalloc(128););
printStats();
void* p219 = last_address;
PRINT_POINTER(scalloc(146,149););
printStats();
void* p220 = last_address;
PRINT_POINTER(scalloc(235,217););
printStats();
void* p221 = last_address;
PRINT_POINTER(srealloc(p124,199););
printStats();
void* p222 = last_address;
PRINT_POINTER(smalloc(86););
printStats();
void* p223 = last_address;
PRINT_POINTER(scalloc(155,75););
printStats();
void* p224 = last_address;
PRINT_POINTER(srealloc(p185,220););
printStats();
void* p225 = last_address;
PRINT_POINTER(scalloc(114,220););
printStats();
void* p226 = last_address;
DEBUG_PRINT(sfree(p159););
printStats();
PRINT_POINTER(srealloc(p179,249););
printStats();
void* p227 = last_address;
PRINT_POINTER(scalloc(238,114););
printStats();
void* p228 = last_address;
PRINT_POINTER(srealloc(p148,199););
printStats();
void* p229 = last_address;
PRINT_POINTER(smalloc(227););
printStats();
void* p230 = last_address;
PRINT_POINTER(srealloc(p196,113););
printStats();
void* p231 = last_address;
PRINT_POINTER(srealloc(p173,8););
printStats();
void* p232 = last_address;
PRINT_POINTER(smalloc(19););
printStats();
void* p233 = last_address;
DEBUG_PRINT(sfree(p227););
printStats();
PRINT_POINTER(scalloc(198,14););
printStats();
void* p234 = last_address;
DEBUG_PRINT(sfree(p216););
printStats();
PRINT_POINTER(smalloc(28););
printStats();
void* p235 = last_address;
PRINT_POINTER(srealloc(p208,226););
printStats();
void* p236 = last_address;
PRINT_POINTER(scalloc(128,15););
printStats();
void* p237 = last_address;
DEBUG_PRINT(sfree(p130););
printStats();
PRINT_POINTER(scalloc(155,229););
printStats();
void* p238 = last_address;
PRINT_POINTER(scalloc(118,143););
printStats();
void* p239 = last_address;
PRINT_POINTER(scalloc(32,86););
printStats();
void* p240 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p241 = last_address;
PRINT_POINTER(smalloc(248););
printStats();
void* p242 = last_address;
PRINT_POINTER(scalloc(81,68););
printStats();
void* p243 = last_address;
DEBUG_PRINT(sfree(p53););
printStats();
PRINT_POINTER(scalloc(46,171););
printStats();
void* p244 = last_address;
DEBUG_PRINT(sfree(p187););
printStats();
PRINT_POINTER(smalloc(72););
printStats();
void* p245 = last_address;
PRINT_POINTER(srealloc(p206,28););
printStats();
void* p246 = last_address;
PRINT_POINTER(scalloc(139,2););
printStats();
void* p247 = last_address;
PRINT_POINTER(srealloc(p197,105););
printStats();
void* p248 = last_address;
DEBUG_PRINT(sfree(p188););
printStats();
PRINT_POINTER(scalloc(202,129););
printStats();
void* p249 = last_address;
PRINT_POINTER(scalloc(40,165););
printStats();
void* p250 = last_address;
PRINT_POINTER(srealloc(p233,20););
printStats();
void* p251 = last_address;
PRINT_POINTER(smalloc(29););
printStats();
void* p252 = last_address;
PRINT_POINTER(smalloc(89););
printStats();
void* p253 = last_address;
PRINT_POINTER(srealloc(p210,126););
printStats();
void* p254 = last_address;
PRINT_POINTER(srealloc(p232,108););
printStats();
void* p255 = last_address;
PRINT_POINTER(scalloc(49,185););
printStats();
void* p256 = last_address;
DEBUG_PRINT(sfree(p252););
printStats();
DEBUG_PRINT(sfree(p150););
printStats();
DEBUG_PRINT(sfree(p237););
printStats();
PRINT_POINTER(smalloc(39););
printStats();
void* p257 = last_address;
PRINT_POINTER(srealloc(p214,128););
printStats();
void* p258 = last_address;
DEBUG_PRINT(sfree(p61););
printStats();
DEBUG_PRINT(sfree(p204););
printStats();
PRINT_POINTER(smalloc(5););
printStats();
void* p259 = last_address;
PRINT_POINTER(smalloc(57););
printStats();
void* p260 = last_address;
PRINT_POINTER(srealloc(p135,65););
printStats();
void* p261 = last_address;
PRINT_POINTER(scalloc(103,188););
printStats();
void* p262 = last_address;
PRINT_POINTER(srealloc(p79,125););
printStats();
void* p263 = last_address;
DEBUG_PRINT(sfree(p239););
printStats();
DEBUG_PRINT(sfree(p209););
printStats();
PRINT_POINTER(smalloc(131););
printStats();
void* p264 = last_address;
DEBUG_PRINT(sfree(p220););
printStats();
PRINT_POINTER(scalloc(248,210););
printStats();
void* p265 = last_address;
DEBUG_PRINT(sfree(p238););
printStats();
DEBUG_PRINT(sfree(p192););
printStats();
PRINT_POINTER(srealloc(p229,112););
printStats();
void* p266 = last_address;
PRINT_POINTER(srealloc(p219,4););
printStats();
void* p267 = last_address;
PRINT_POINTER(srealloc(p244,102););
printStats();
void* p268 = last_address;
PRINT_POINTER(scalloc(145,162););
printStats();
void* p269 = last_address;
PRINT_POINTER(srealloc(p221,146););
printStats();
void* p270 = last_address;
PRINT_POINTER(scalloc(37,194););
printStats();
void* p271 = last_address;
PRINT_POINTER(srealloc(p178,224););
printStats();
void* p272 = last_address;
PRINT_POINTER(srealloc(p117,173););
printStats();
void* p273 = last_address;
PRINT_POINTER(scalloc(41,231););
printStats();
void* p274 = last_address;
PRINT_POINTER(srealloc(p122,45););
printStats();
void* p275 = last_address;
PRINT_POINTER(scalloc(226,42););
printStats();
void* p276 = last_address;
DEBUG_PRINT(sfree(p264););
printStats();
DEBUG_PRINT(sfree(p184););
printStats();
PRINT_POINTER(smalloc(114););
printStats();
void* p277 = last_address;
PRINT_POINTER(scalloc(43,248););
printStats();
void* p278 = last_address;
PRINT_POINTER(srealloc(p169,158););
printStats();
void* p279 = last_address;
DEBUG_PRINT(sfree(p152););
printStats();
PRINT_POINTER(smalloc(192););
printStats();
void* p280 = last_address;
PRINT_POINTER(srealloc(p251,36););
printStats();
void* p281 = last_address;
PRINT_POINTER(smalloc(153););
printStats();
void* p282 = last_address;
PRINT_POINTER(scalloc(239,154););
printStats();
void* p283 = last_address;
DEBUG_PRINT(sfree(p162););
printStats();
PRINT_POINTER(scalloc(22,2););
printStats();
void* p284 = last_address;
PRINT_POINTER(srealloc(p177,237););
printStats();
void* p285 = last_address;
PRINT_POINTER(srealloc(p226,211););
printStats();
void* p286 = last_address;
PRINT_POINTER(srealloc(p270,27););
printStats();
void* p287 = last_address;
PRINT_POINTER(smalloc(80););
printStats();
void* p288 = last_address;
PRINT_POINTER(smalloc(33););
printStats();
void* p289 = last_address;
DEBUG_PRINT(sfree(p99););
printStats();
DEBUG_PRINT(sfree(p141););
printStats();
PRINT_POINTER(srealloc(p140,229););
printStats();
void* p290 = last_address;
DEBUG_PRINT(sfree(p228););
printStats();
PRINT_POINTER(scalloc(40,194););
printStats();
void* p291 = last_address;
PRINT_POINTER(srealloc(p215,225););
printStats();
void* p292 = last_address;
PRINT_POINTER(smalloc(138););
printStats();
void* p293 = last_address;
DEBUG_PRINT(sfree(p147););
printStats();
PRINT_POINTER(scalloc(40,70););
printStats();
void* p294 = last_address;
PRINT_POINTER(scalloc(69,239););
printStats();
void* p295 = last_address;
PRINT_POINTER(scalloc(66,78););
printStats();
void* p296 = last_address;
DEBUG_PRINT(sfree(p241););
printStats();
PRINT_POINTER(srealloc(p280,8););
printStats();
void* p297 = last_address;
PRINT_POINTER(scalloc(147,237););
printStats();
void* p298 = last_address;
DEBUG_PRINT(sfree(p267););
printStats();
PRINT_POINTER(srealloc(p213,42););
printStats();
void* p299 = last_address;
PRINT_POINTER(smalloc(66););
printStats();
void* p300 = last_address;
PRINT_POINTER(srealloc(p279,224););
printStats();
void* p301 = last_address;
DEBUG_PRINT(sfree(p243););
printStats();
DEBUG_PRINT(sfree(p268););
printStats();
PRINT_POINTER(srealloc(p181,63););
printStats();
void* p302 = last_address;
PRINT_POINTER(srealloc(p300,156););
printStats();
void* p303 = last_address;
PRINT_POINTER(srealloc(p250,25););
printStats();
void* p304 = last_address;
PRINT_POINTER(smalloc(195););
printStats();
void* p305 = last_address;
PRINT_POINTER(srealloc(p301,243););
printStats();
void* p306 = last_address;
DEBUG_PRINT(sfree(p218););
printStats();
PRINT_POINTER(srealloc(p158,196););
printStats();
void* p307 = last_address;
DEBUG_PRINT(sfree(p222););
printStats();
DEBUG_PRINT(sfree(p225););
printStats();
PRINT_POINTER(srealloc(p193,12););
printStats();
void* p308 = last_address;
PRINT_POINTER(smalloc(153););
printStats();
void* p309 = last_address;
PRINT_POINTER(scalloc(15,116););
printStats();
void* p310 = last_address;
DEBUG_PRINT(sfree(p258););
printStats();
PRINT_POINTER(scalloc(229,98););
printStats();
void* p311 = last_address;
PRINT_POINTER(srealloc(p224,126););
printStats();
void* p312 = last_address;
DEBUG_PRINT(sfree(p212););
printStats();
PRINT_POINTER(scalloc(147,81););
printStats();
void* p313 = last_address;
PRINT_POINTER(srealloc(p266,40););
printStats();
void* p314 = last_address;
PRINT_POINTER(scalloc(210,112););
printStats();
void* p315 = last_address;
PRINT_POINTER(smalloc(211););
printStats();
void* p316 = last_address;
PRINT_POINTER(srealloc(p299,86););
printStats();
void* p317 = last_address;
PRINT_POINTER(srealloc(p298,130););
printStats();
void* p318 = last_address;
PRINT_POINTER(scalloc(230,152););
printStats();
void* p319 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p320 = last_address;
PRINT_POINTER(smalloc(186););
printStats();
void* p321 = last_address;
DEBUG_PRINT(sfree(p161););
printStats();
PRINT_POINTER(srealloc(p144,124););
printStats();
void* p322 = last_address;
DEBUG_PRINT(sfree(p253););
printStats();
PRINT_POINTER(srealloc(p305,163););
printStats();
void* p323 = last_address;
PRINT_POINTER(smalloc(67););
printStats();
void* p324 = last_address;
PRINT_POINTER(smalloc(43););
printStats();
void* p325 = last_address;
PRINT_POINTER(srealloc(p314,180););
printStats();
void* p326 = last_address;
DEBUG_PRINT(sfree(p133););
printStats();
DEBUG_PRINT(sfree(p283););
printStats();
PRINT_POINTER(smalloc(172););
printStats();
void* p327 = last_address;
DEBUG_PRINT(sfree(p203););
printStats();
PRINT_POINTER(srealloc(p157,215););
printStats();
void* p328 = last_address;
PRINT_POINTER(srealloc(p247,65););
printStats();
void* p329 = last_address;
PRINT_POINTER(scalloc(137,144););
printStats();
void* p330 = last_address;
PRINT_POINTER(srealloc(p271,121););
printStats();
void* p331 = last_address;
PRINT_POINTER(smalloc(85););
printStats();
void* p332 = last_address;
PRINT_POINTER(srealloc(p306,69););
printStats();
void* p333 = last_address;
DEBUG_PRINT(sfree(p198););
printStats();
PRINT_POINTER(scalloc(106,198););
printStats();
void* p334 = last_address;
PRINT_POINTER(scalloc(202,8););
printStats();
void* p335 = last_address;
DEBUG_PRINT(sfree(p234););
printStats();
DEBUG_PRINT(sfree(p186););
printStats();
PRINT_POINTER(smalloc(218););
printStats();
void* p336 = last_address;
PRINT_POINTER(scalloc(187,209););
printStats();
void* p337 = last_address;
DEBUG_PRINT(sfree(p308););
printStats();
PRINT_POINTER(srealloc(p336,116););
printStats();
void* p338 = last_address;
PRINT_POINTER(scalloc(196,179););
printStats();
void* p339 = last_address;
PRINT_POINTER(scalloc(151,42););
printStats();
void* p340 = last_address;
PRINT_POINTER(scalloc(122,107););
printStats();
void* p341 = last_address;
PRINT_POINTER(scalloc(40,85););
printStats();
void* p342 = last_address;
PRINT_POINTER(scalloc(126,156););
printStats();
void* p343 = last_address;
DEBUG_PRINT(sfree(p319););
printStats();
PRINT_POINTER(srealloc(p164,138););
printStats();
void* p344 = last_address;
PRINT_POINTER(scalloc(248,65););
printStats();
void* p345 = last_address;
PRINT_POINTER(scalloc(112,174););
printStats();
void* p346 = last_address;
PRINT_POINTER(smalloc(184););
printStats();
void* p347 = last_address;
PRINT_POINTER(scalloc(101,241););
printStats();
void* p348 = last_address;
PRINT_POINTER(smalloc(73););
printStats();
void* p349 = last_address;
PRINT_POINTER(scalloc(197,129););
printStats();
void* p350 = last_address;
PRINT_POINTER(srealloc(p257,185););
printStats();
void* p351 = last_address;
PRINT_POINTER(srealloc(p309,98););
printStats();
void* p352 = last_address;
DEBUG_PRINT(sfree(p310););
printStats();
DEBUG_PRINT(sfree(p328););
printStats();
PRINT_POINTER(srealloc(p340,31););
printStats();
void* p353 = last_address;
PRINT_POINTER(smalloc(41););
printStats();
void* p354 = last_address;
PRINT_POINTER(smalloc(123););
printStats();
void* p355 = last_address;
PRINT_POINTER(scalloc(0,99););
printStats();
void* p356 = last_address;
PRINT_POINTER(srealloc(p255,3););
printStats();
void* p357 = last_address;
DEBUG_PRINT(sfree(p168););
printStats();
PRINT_POINTER(srealloc(p180,5););
printStats();
void* p358 = last_address;
PRINT_POINTER(scalloc(242,11););
printStats();
void* p359 = last_address;
DEBUG_PRINT(sfree(p325););
printStats();
PRINT_POINTER(smalloc(22););
printStats();
void* p360 = last_address;
PRINT_POINTER(scalloc(239,103););
printStats();
void* p361 = last_address;
DEBUG_PRINT(sfree(p170););
printStats();
PRINT_POINTER(smalloc(156););
printStats();
void* p362 = last_address;
PRINT_POINTER(scalloc(166,18););
printStats();
void* p363 = last_address;
PRINT_POINTER(smalloc(153););
printStats();
void* p364 = last_address;
PRINT_POINTER(scalloc(59,235););
printStats();
void* p365 = last_address;
PRINT_POINTER(srealloc(p350,98););
printStats();
void* p366 = last_address;
PRINT_POINTER(scalloc(248,101););
printStats();
void* p367 = last_address;
PRINT_POINTER(scalloc(207,142););
printStats();
void* p368 = last_address;
DEBUG_PRINT(sfree(p262););
printStats();
DEBUG_PRINT(sfree(p249););
printStats();
PRINT_POINTER(smalloc(184););
printStats();
void* p369 = last_address;
DEBUG_PRINT(sfree(p223););
printStats();
PRINT_POINTER(smalloc(238););
printStats();
void* p370 = last_address;
PRINT_POINTER(srealloc(p172,19););
printStats();
void* p371 = last_address;
PRINT_POINTER(srealloc(p364,59););
printStats();
void* p372 = last_address;
DEBUG_PRINT(sfree(p354););
printStats();
PRINT_POINTER(scalloc(209,211););
printStats();
void* p373 = last_address;
PRINT_POINTER(smalloc(186););
printStats();
void* p374 = last_address;
DEBUG_PRINT(sfree(p293););
printStats();
PRINT_POINTER(scalloc(45,115););
printStats();
void* p375 = last_address;
PRINT_POINTER(scalloc(28,170););
printStats();
void* p376 = last_address;
PRINT_POINTER(smalloc(31););
printStats();
void* p377 = last_address;
DEBUG_PRINT(sfree(p371););
printStats();
DEBUG_PRINT(sfree(p278););
printStats();
PRINT_POINTER(scalloc(112,232););
printStats();
void* p378 = last_address;
PRINT_POINTER(scalloc(14,148););
printStats();
void* p379 = last_address;
PRINT_POINTER(scalloc(128,219););
printStats();
void* p380 = last_address;
PRINT_POINTER(srealloc(p284,115););
printStats();
void* p381 = last_address;
PRINT_POINTER(smalloc(23););
printStats();
void* p382 = last_address;
PRINT_POINTER(srealloc(p379,248););
printStats();
void* p383 = last_address;
PRINT_POINTER(srealloc(p373,137););
printStats();
void* p384 = last_address;
PRINT_POINTER(smalloc(199););
printStats();
void* p385 = last_address;
PRINT_POINTER(srealloc(p322,76););
printStats();
void* p386 = last_address;
DEBUG_PRINT(sfree(p374););
printStats();
PRINT_POINTER(scalloc(149,235););
printStats();
void* p387 = last_address;
PRINT_POINTER(smalloc(140););
printStats();
void* p388 = last_address;
PRINT_POINTER(smalloc(223););
printStats();
void* p389 = last_address;
PRINT_POINTER(srealloc(p292,104););
printStats();
void* p390 = last_address;
PRINT_POINTER(srealloc(p359,114););
printStats();
void* p391 = last_address;
PRINT_POINTER(scalloc(67,142););
printStats();
void* p392 = last_address;
PRINT_POINTER(srealloc(p367,249););
printStats();
void* p393 = last_address;
PRINT_POINTER(smalloc(5););
printStats();
void* p394 = last_address;
PRINT_POINTER(smalloc(38););
printStats();
void* p395 = last_address;
PRINT_POINTER(smalloc(30););
printStats();
void* p396 = last_address;
PRINT_POINTER(smalloc(55););
printStats();
void* p397 = last_address;
PRINT_POINTER(scalloc(145,178););
printStats();
void* p398 = last_address;
PRINT_POINTER(scalloc(0,54););
printStats();
void* p399 = last_address;
PRINT_POINTER(srealloc(p217,229););
printStats();
void* p400 = last_address;
DEBUG_PRINT(sfree(p296););
printStats();
DEBUG_PRINT(sfree(p281););
printStats();
PRINT_POINTER(scalloc(142,37););
printStats();
void* p401 = last_address;
PRINT_POINTER(srealloc(p318,233););
printStats();
void* p402 = last_address;
PRINT_POINTER(scalloc(49,190););
printStats();
void* p403 = last_address;
PRINT_POINTER(smalloc(22););
printStats();
void* p404 = last_address;
PRINT_POINTER(srealloc(p285,167););
printStats();
void* p405 = last_address;
DEBUG_PRINT(sfree(p235););
printStats();
PRINT_POINTER(scalloc(202,27););
printStats();
void* p406 = last_address;
PRINT_POINTER(srealloc(p398,144););
printStats();
void* p407 = last_address;
DEBUG_PRINT(sfree(p360););
printStats();
PRINT_POINTER(smalloc(131););
printStats();
void* p408 = last_address;
PRINT_POINTER(srealloc(p376,56););
printStats();
void* p409 = last_address;
PRINT_POINTER(scalloc(157,63););
printStats();
void* p410 = last_address;
PRINT_POINTER(smalloc(173););
printStats();
void* p411 = last_address;
DEBUG_PRINT(sfree(p321););
printStats();
DEBUG_PRINT(sfree(p347););
printStats();
PRINT_POINTER(srealloc(p254,141););
printStats();
void* p412 = last_address;
PRINT_POINTER(smalloc(138););
printStats();
void* p413 = last_address;
PRINT_POINTER(scalloc(156,161););
printStats();
void* p414 = last_address;
PRINT_POINTER(srealloc(p342,201););
printStats();
void* p415 = last_address;
DEBUG_PRINT(sfree(p330););
printStats();
PRINT_POINTER(smalloc(70););
printStats();
void* p416 = last_address;
PRINT_POINTER(scalloc(92,170););
printStats();
void* p417 = last_address;
PRINT_POINTER(srealloc(p327,126););
printStats();
void* p418 = last_address;
DEBUG_PRINT(sfree(p304););
printStats();
PRINT_POINTER(srealloc(p415,102););
printStats();
void* p419 = last_address;
PRINT_POINTER(srealloc(p395,171););
printStats();
void* p420 = last_address;
PRINT_POINTER(srealloc(p386,108););
printStats();
void* p421 = last_address;
PRINT_POINTER(smalloc(209););
printStats();
void* p422 = last_address;
PRINT_POINTER(smalloc(230););
printStats();
void* p423 = last_address;
DEBUG_PRINT(sfree(p411););
printStats();
PRINT_POINTER(smalloc(146););
printStats();
void* p424 = last_address;
PRINT_POINTER(smalloc(99););
printStats();
void* p425 = last_address;
DEBUG_PRINT(sfree(p127););
printStats();
DEBUG_PRINT(sfree(p275););
printStats();
}
