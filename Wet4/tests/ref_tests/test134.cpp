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
                        PRINT_POINTER(scalloc(211,34););
printStats();
void* p0 = last_address;
PRINT_POINTER(srealloc(p0,95););
printStats();
void* p1 = last_address;
PRINT_POINTER(srealloc(p1,237););
printStats();
void* p2 = last_address;
PRINT_POINTER(srealloc(p2,4););
printStats();
void* p3 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
PRINT_POINTER(scalloc(216,163););
printStats();
void* p4 = last_address;
PRINT_POINTER(smalloc(52););
printStats();
void* p5 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(srealloc(p5,209););
printStats();
void* p6 = last_address;
PRINT_POINTER(smalloc(203););
printStats();
void* p7 = last_address;
PRINT_POINTER(scalloc(169,121););
printStats();
void* p8 = last_address;
PRINT_POINTER(scalloc(206,222););
printStats();
void* p9 = last_address;
PRINT_POINTER(smalloc(218););
printStats();
void* p10 = last_address;
PRINT_POINTER(scalloc(176,73););
printStats();
void* p11 = last_address;
PRINT_POINTER(srealloc(p10,70););
printStats();
void* p12 = last_address;
PRINT_POINTER(scalloc(121,54););
printStats();
void* p13 = last_address;
PRINT_POINTER(scalloc(100,158););
printStats();
void* p14 = last_address;
DEBUG_PRINT(sfree(p9););
printStats();
PRINT_POINTER(srealloc(p7,214););
printStats();
void* p15 = last_address;
PRINT_POINTER(scalloc(38,126););
printStats();
void* p16 = last_address;
PRINT_POINTER(smalloc(62););
printStats();
void* p17 = last_address;
PRINT_POINTER(smalloc(75););
printStats();
void* p18 = last_address;
PRINT_POINTER(srealloc(p11,28););
printStats();
void* p19 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(srealloc(p17,81););
printStats();
void* p20 = last_address;
DEBUG_PRINT(sfree(p8););
printStats();
PRINT_POINTER(scalloc(221,142););
printStats();
void* p21 = last_address;
DEBUG_PRINT(sfree(p14););
printStats();
DEBUG_PRINT(sfree(p18););
printStats();
PRINT_POINTER(srealloc(p16,80););
printStats();
void* p22 = last_address;
PRINT_POINTER(scalloc(94,227););
printStats();
void* p23 = last_address;
DEBUG_PRINT(sfree(p12););
printStats();
PRINT_POINTER(smalloc(112););
printStats();
void* p24 = last_address;
PRINT_POINTER(scalloc(184,155););
printStats();
void* p25 = last_address;
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(srealloc(p25,44););
printStats();
void* p26 = last_address;
PRINT_POINTER(srealloc(p19,105););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(144,193););
printStats();
void* p28 = last_address;
PRINT_POINTER(smalloc(186););
printStats();
void* p29 = last_address;
DEBUG_PRINT(sfree(p29););
printStats();
PRINT_POINTER(srealloc(p26,224););
printStats();
void* p30 = last_address;
PRINT_POINTER(smalloc(55););
printStats();
void* p31 = last_address;
DEBUG_PRINT(sfree(p24););
printStats();
DEBUG_PRINT(sfree(p28););
printStats();
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(scalloc(62,224););
printStats();
void* p32 = last_address;
DEBUG_PRINT(sfree(p21););
printStats();
PRINT_POINTER(scalloc(147,67););
printStats();
void* p33 = last_address;
PRINT_POINTER(scalloc(78,63););
printStats();
void* p34 = last_address;
PRINT_POINTER(srealloc(p33,187););
printStats();
void* p35 = last_address;
DEBUG_PRINT(sfree(p13););
printStats();
PRINT_POINTER(smalloc(215););
printStats();
void* p36 = last_address;
PRINT_POINTER(srealloc(p30,158););
printStats();
void* p37 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p38 = last_address;
PRINT_POINTER(scalloc(132,138););
printStats();
void* p39 = last_address;
PRINT_POINTER(smalloc(128););
printStats();
void* p40 = last_address;
PRINT_POINTER(srealloc(p27,74););
printStats();
void* p41 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(smalloc(58););
printStats();
void* p42 = last_address;
DEBUG_PRINT(sfree(p37););
printStats();
PRINT_POINTER(srealloc(p35,116););
printStats();
void* p43 = last_address;
PRINT_POINTER(scalloc(118,155););
printStats();
void* p44 = last_address;
PRINT_POINTER(srealloc(p38,29););
printStats();
void* p45 = last_address;
PRINT_POINTER(smalloc(97););
printStats();
void* p46 = last_address;
PRINT_POINTER(scalloc(227,82););
printStats();
void* p47 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(srealloc(p41,78););
printStats();
void* p48 = last_address;
PRINT_POINTER(scalloc(137,79););
printStats();
void* p49 = last_address;
PRINT_POINTER(srealloc(p31,19););
printStats();
void* p50 = last_address;
PRINT_POINTER(srealloc(p22,3););
printStats();
void* p51 = last_address;
PRINT_POINTER(scalloc(111,185););
printStats();
void* p52 = last_address;
PRINT_POINTER(srealloc(p50,141););
printStats();
void* p53 = last_address;
PRINT_POINTER(srealloc(p45,20););
printStats();
void* p54 = last_address;
DEBUG_PRINT(sfree(p39););
printStats();
PRINT_POINTER(scalloc(54,219););
printStats();
void* p55 = last_address;
PRINT_POINTER(scalloc(109,208););
printStats();
void* p56 = last_address;
PRINT_POINTER(smalloc(177););
printStats();
void* p57 = last_address;
DEBUG_PRINT(sfree(p44););
printStats();
PRINT_POINTER(srealloc(p52,133););
printStats();
void* p58 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
DEBUG_PRINT(sfree(p42););
printStats();
PRINT_POINTER(srealloc(p47,100););
printStats();
void* p59 = last_address;
DEBUG_PRINT(sfree(p54););
printStats();
PRINT_POINTER(srealloc(p36,167););
printStats();
void* p60 = last_address;
PRINT_POINTER(scalloc(218,152););
printStats();
void* p61 = last_address;
PRINT_POINTER(scalloc(177,118););
printStats();
void* p62 = last_address;
PRINT_POINTER(smalloc(154););
printStats();
void* p63 = last_address;
PRINT_POINTER(scalloc(228,37););
printStats();
void* p64 = last_address;
PRINT_POINTER(srealloc(p63,50););
printStats();
void* p65 = last_address;
PRINT_POINTER(smalloc(6););
printStats();
void* p66 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
PRINT_POINTER(srealloc(p60,204););
printStats();
void* p67 = last_address;
PRINT_POINTER(smalloc(149););
printStats();
void* p68 = last_address;
PRINT_POINTER(scalloc(148,91););
printStats();
void* p69 = last_address;
PRINT_POINTER(srealloc(p64,120););
printStats();
void* p70 = last_address;
PRINT_POINTER(scalloc(197,140););
printStats();
void* p71 = last_address;
DEBUG_PRINT(sfree(p66););
printStats();
PRINT_POINTER(smalloc(240););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(91,51););
printStats();
void* p73 = last_address;
DEBUG_PRINT(sfree(p61););
printStats();
PRINT_POINTER(smalloc(46););
printStats();
void* p74 = last_address;
PRINT_POINTER(smalloc(99););
printStats();
void* p75 = last_address;
PRINT_POINTER(scalloc(86,135););
printStats();
void* p76 = last_address;
PRINT_POINTER(smalloc(94););
printStats();
void* p77 = last_address;
DEBUG_PRINT(sfree(p65););
printStats();
DEBUG_PRINT(sfree(p57););
printStats();
DEBUG_PRINT(sfree(p48););
printStats();
PRINT_POINTER(scalloc(76,188););
printStats();
void* p78 = last_address;
PRINT_POINTER(scalloc(184,107););
printStats();
void* p79 = last_address;
PRINT_POINTER(smalloc(5););
printStats();
void* p80 = last_address;
PRINT_POINTER(smalloc(146););
printStats();
void* p81 = last_address;
DEBUG_PRINT(sfree(p53););
printStats();
PRINT_POINTER(smalloc(71););
printStats();
void* p82 = last_address;
PRINT_POINTER(srealloc(p72,222););
printStats();
void* p83 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(srealloc(p81,74););
printStats();
void* p84 = last_address;
PRINT_POINTER(smalloc(48););
printStats();
void* p85 = last_address;
PRINT_POINTER(srealloc(p51,107););
printStats();
void* p86 = last_address;
PRINT_POINTER(scalloc(143,98););
printStats();
void* p87 = last_address;
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(srealloc(p58,152););
printStats();
void* p88 = last_address;
DEBUG_PRINT(sfree(p59););
printStats();
PRINT_POINTER(smalloc(217););
printStats();
void* p89 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p90 = last_address;
DEBUG_PRINT(sfree(p74););
printStats();
PRINT_POINTER(smalloc(101););
printStats();
void* p91 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
PRINT_POINTER(scalloc(156,49););
printStats();
void* p92 = last_address;
PRINT_POINTER(smalloc(9););
printStats();
void* p93 = last_address;
PRINT_POINTER(smalloc(171););
printStats();
void* p94 = last_address;
PRINT_POINTER(scalloc(114,80););
printStats();
void* p95 = last_address;
PRINT_POINTER(srealloc(p92,9););
printStats();
void* p96 = last_address;
PRINT_POINTER(srealloc(p91,3););
printStats();
void* p97 = last_address;
PRINT_POINTER(scalloc(68,58););
printStats();
void* p98 = last_address;
PRINT_POINTER(srealloc(p77,240););
printStats();
void* p99 = last_address;
PRINT_POINTER(smalloc(162););
printStats();
void* p100 = last_address;
PRINT_POINTER(smalloc(235););
printStats();
void* p101 = last_address;
DEBUG_PRINT(sfree(p90););
printStats();
PRINT_POINTER(smalloc(222););
printStats();
void* p102 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
PRINT_POINTER(srealloc(p73,26););
printStats();
void* p103 = last_address;
PRINT_POINTER(srealloc(p78,41););
printStats();
void* p104 = last_address;
DEBUG_PRINT(sfree(p97););
printStats();
DEBUG_PRINT(sfree(p95););
printStats();
PRINT_POINTER(smalloc(135););
printStats();
void* p105 = last_address;
PRINT_POINTER(srealloc(p70,208););
printStats();
void* p106 = last_address;
PRINT_POINTER(srealloc(p46,200););
printStats();
void* p107 = last_address;
DEBUG_PRINT(sfree(p105););
printStats();
PRINT_POINTER(smalloc(62););
printStats();
void* p108 = last_address;
PRINT_POINTER(scalloc(91,150););
printStats();
void* p109 = last_address;
PRINT_POINTER(srealloc(p69,24););
printStats();
void* p110 = last_address;
PRINT_POINTER(scalloc(244,79););
printStats();
void* p111 = last_address;
PRINT_POINTER(srealloc(p88,188););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(183););
printStats();
void* p113 = last_address;
PRINT_POINTER(scalloc(48,159););
printStats();
void* p114 = last_address;
PRINT_POINTER(scalloc(105,120););
printStats();
void* p115 = last_address;
PRINT_POINTER(srealloc(p106,202););
printStats();
void* p116 = last_address;
PRINT_POINTER(scalloc(14,199););
printStats();
void* p117 = last_address;
PRINT_POINTER(smalloc(69););
printStats();
void* p118 = last_address;
PRINT_POINTER(srealloc(p82,245););
printStats();
void* p119 = last_address;
DEBUG_PRINT(sfree(p104););
printStats();
PRINT_POINTER(scalloc(235,185););
printStats();
void* p120 = last_address;
PRINT_POINTER(smalloc(206););
printStats();
void* p121 = last_address;
DEBUG_PRINT(sfree(p112););
printStats();
PRINT_POINTER(scalloc(4,103););
printStats();
void* p122 = last_address;
PRINT_POINTER(srealloc(p62,210););
printStats();
void* p123 = last_address;
PRINT_POINTER(smalloc(24););
printStats();
void* p124 = last_address;
PRINT_POINTER(smalloc(211););
printStats();
void* p125 = last_address;
PRINT_POINTER(smalloc(145););
printStats();
void* p126 = last_address;
PRINT_POINTER(scalloc(172,161););
printStats();
void* p127 = last_address;
PRINT_POINTER(srealloc(p108,29););
printStats();
void* p128 = last_address;
PRINT_POINTER(scalloc(96,246););
printStats();
void* p129 = last_address;
PRINT_POINTER(smalloc(77););
printStats();
void* p130 = last_address;
PRINT_POINTER(smalloc(146););
printStats();
void* p131 = last_address;
PRINT_POINTER(srealloc(p76,178););
printStats();
void* p132 = last_address;
DEBUG_PRINT(sfree(p121););
printStats();
PRINT_POINTER(smalloc(202););
printStats();
void* p133 = last_address;
PRINT_POINTER(scalloc(166,6););
printStats();
void* p134 = last_address;
PRINT_POINTER(srealloc(p94,56););
printStats();
void* p135 = last_address;
PRINT_POINTER(scalloc(53,179););
printStats();
void* p136 = last_address;
PRINT_POINTER(smalloc(46););
printStats();
void* p137 = last_address;
DEBUG_PRINT(sfree(p75););
printStats();
PRINT_POINTER(scalloc(111,230););
printStats();
void* p138 = last_address;
DEBUG_PRINT(sfree(p99););
printStats();
PRINT_POINTER(smalloc(232););
printStats();
void* p139 = last_address;
PRINT_POINTER(scalloc(149,191););
printStats();
void* p140 = last_address;
PRINT_POINTER(scalloc(176,96););
printStats();
void* p141 = last_address;
DEBUG_PRINT(sfree(p117););
printStats();
PRINT_POINTER(srealloc(p107,75););
printStats();
void* p142 = last_address;
PRINT_POINTER(scalloc(174,88););
printStats();
void* p143 = last_address;
PRINT_POINTER(smalloc(204););
printStats();
void* p144 = last_address;
PRINT_POINTER(srealloc(p67,91););
printStats();
void* p145 = last_address;
PRINT_POINTER(scalloc(173,69););
printStats();
void* p146 = last_address;
PRINT_POINTER(srealloc(p145,208););
printStats();
void* p147 = last_address;
PRINT_POINTER(scalloc(226,47););
printStats();
void* p148 = last_address;
PRINT_POINTER(smalloc(54););
printStats();
void* p149 = last_address;
DEBUG_PRINT(sfree(p122););
printStats();
PRINT_POINTER(srealloc(p98,118););
printStats();
void* p150 = last_address;
PRINT_POINTER(srealloc(p144,147););
printStats();
void* p151 = last_address;
DEBUG_PRINT(sfree(p147););
printStats();
PRINT_POINTER(smalloc(227););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p113,177););
printStats();
void* p153 = last_address;
DEBUG_PRINT(sfree(p83););
printStats();
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(srealloc(p103,187););
printStats();
void* p154 = last_address;
DEBUG_PRINT(sfree(p146););
printStats();
PRINT_POINTER(smalloc(14););
printStats();
void* p155 = last_address;
DEBUG_PRINT(sfree(p141););
printStats();
PRINT_POINTER(srealloc(p101,120););
printStats();
void* p156 = last_address;
DEBUG_PRINT(sfree(p123););
printStats();
PRINT_POINTER(scalloc(116,198););
printStats();
void* p157 = last_address;
DEBUG_PRINT(sfree(p127););
printStats();
DEBUG_PRINT(sfree(p128););
printStats();
DEBUG_PRINT(sfree(p71););
printStats();
PRINT_POINTER(smalloc(115););
printStats();
void* p158 = last_address;
PRINT_POINTER(smalloc(195););
printStats();
void* p159 = last_address;
DEBUG_PRINT(sfree(p116););
printStats();
PRINT_POINTER(scalloc(248,91););
printStats();
void* p160 = last_address;
PRINT_POINTER(smalloc(7););
printStats();
void* p161 = last_address;
PRINT_POINTER(scalloc(240,38););
printStats();
void* p162 = last_address;
PRINT_POINTER(srealloc(p148,244););
printStats();
void* p163 = last_address;
PRINT_POINTER(scalloc(204,26););
printStats();
void* p164 = last_address;
DEBUG_PRINT(sfree(p142););
printStats();
PRINT_POINTER(scalloc(104,123););
printStats();
void* p165 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p166 = last_address;
DEBUG_PRINT(sfree(p68););
printStats();
PRINT_POINTER(srealloc(p161,167););
printStats();
void* p167 = last_address;
PRINT_POINTER(srealloc(p109,142););
printStats();
void* p168 = last_address;
PRINT_POINTER(scalloc(186,113););
printStats();
void* p169 = last_address;
PRINT_POINTER(scalloc(152,132););
printStats();
void* p170 = last_address;
PRINT_POINTER(srealloc(p163,86););
printStats();
void* p171 = last_address;
DEBUG_PRINT(sfree(p168););
printStats();
PRINT_POINTER(srealloc(p124,52););
printStats();
void* p172 = last_address;
PRINT_POINTER(smalloc(125););
printStats();
void* p173 = last_address;
PRINT_POINTER(scalloc(167,203););
printStats();
void* p174 = last_address;
PRINT_POINTER(smalloc(129););
printStats();
void* p175 = last_address;
PRINT_POINTER(smalloc(171););
printStats();
void* p176 = last_address;
PRINT_POINTER(scalloc(182,108););
printStats();
void* p177 = last_address;
PRINT_POINTER(scalloc(234,180););
printStats();
void* p178 = last_address;
PRINT_POINTER(smalloc(89););
printStats();
void* p179 = last_address;
DEBUG_PRINT(sfree(p166););
printStats();
PRINT_POINTER(srealloc(p100,241););
printStats();
void* p180 = last_address;
PRINT_POINTER(srealloc(p93,52););
printStats();
void* p181 = last_address;
PRINT_POINTER(srealloc(p134,202););
printStats();
void* p182 = last_address;
PRINT_POINTER(smalloc(160););
printStats();
void* p183 = last_address;
PRINT_POINTER(srealloc(p151,143););
printStats();
void* p184 = last_address;
PRINT_POINTER(srealloc(p183,34););
printStats();
void* p185 = last_address;
PRINT_POINTER(scalloc(249,222););
printStats();
void* p186 = last_address;
PRINT_POINTER(smalloc(13););
printStats();
void* p187 = last_address;
PRINT_POINTER(scalloc(14,41););
printStats();
void* p188 = last_address;
PRINT_POINTER(srealloc(p115,45););
printStats();
void* p189 = last_address;
PRINT_POINTER(srealloc(p110,25););
printStats();
void* p190 = last_address;
PRINT_POINTER(scalloc(43,184););
printStats();
void* p191 = last_address;
PRINT_POINTER(srealloc(p86,26););
printStats();
void* p192 = last_address;
DEBUG_PRINT(sfree(p138););
printStats();
PRINT_POINTER(scalloc(60,177););
printStats();
void* p193 = last_address;
PRINT_POINTER(srealloc(p191,11););
printStats();
void* p194 = last_address;
PRINT_POINTER(srealloc(p129,214););
printStats();
void* p195 = last_address;
PRINT_POINTER(srealloc(p193,146););
printStats();
void* p196 = last_address;
DEBUG_PRINT(sfree(p143););
printStats();
DEBUG_PRINT(sfree(p174););
printStats();
PRINT_POINTER(srealloc(p175,226););
printStats();
void* p197 = last_address;
PRINT_POINTER(scalloc(136,8););
printStats();
void* p198 = last_address;
PRINT_POINTER(scalloc(177,171););
printStats();
void* p199 = last_address;
DEBUG_PRINT(sfree(p130););
printStats();
PRINT_POINTER(scalloc(194,211););
printStats();
void* p200 = last_address;
PRINT_POINTER(srealloc(p192,39););
printStats();
void* p201 = last_address;
PRINT_POINTER(smalloc(134););
printStats();
void* p202 = last_address;
PRINT_POINTER(srealloc(p153,87););
printStats();
void* p203 = last_address;
PRINT_POINTER(scalloc(3,108););
printStats();
void* p204 = last_address;
PRINT_POINTER(scalloc(79,134););
printStats();
void* p205 = last_address;
PRINT_POINTER(srealloc(p169,72););
printStats();
void* p206 = last_address;
PRINT_POINTER(smalloc(74););
printStats();
void* p207 = last_address;
PRINT_POINTER(smalloc(50););
printStats();
void* p208 = last_address;
PRINT_POINTER(scalloc(49,155););
printStats();
void* p209 = last_address;
DEBUG_PRINT(sfree(p159););
printStats();
DEBUG_PRINT(sfree(p43););
printStats();
PRINT_POINTER(smalloc(246););
printStats();
void* p210 = last_address;
DEBUG_PRINT(sfree(p154););
printStats();
PRINT_POINTER(scalloc(3,6););
printStats();
void* p211 = last_address;
PRINT_POINTER(smalloc(106););
printStats();
void* p212 = last_address;
PRINT_POINTER(srealloc(p200,56););
printStats();
void* p213 = last_address;
PRINT_POINTER(scalloc(44,58););
printStats();
void* p214 = last_address;
DEBUG_PRINT(sfree(p209););
printStats();
PRINT_POINTER(smalloc(178););
printStats();
void* p215 = last_address;
DEBUG_PRINT(sfree(p215););
printStats();
PRINT_POINTER(smalloc(171););
printStats();
void* p216 = last_address;
PRINT_POINTER(smalloc(21););
printStats();
void* p217 = last_address;
PRINT_POINTER(srealloc(p186,57););
printStats();
void* p218 = last_address;
PRINT_POINTER(srealloc(p177,69););
printStats();
void* p219 = last_address;
PRINT_POINTER(smalloc(200););
printStats();
void* p220 = last_address;
PRINT_POINTER(scalloc(82,120););
printStats();
void* p221 = last_address;
PRINT_POINTER(smalloc(21););
printStats();
void* p222 = last_address;
DEBUG_PRINT(sfree(p152););
printStats();
PRINT_POINTER(srealloc(p190,28););
printStats();
void* p223 = last_address;
PRINT_POINTER(srealloc(p137,18););
printStats();
void* p224 = last_address;
PRINT_POINTER(srealloc(p80,38););
printStats();
void* p225 = last_address;
PRINT_POINTER(scalloc(174,152););
printStats();
void* p226 = last_address;
PRINT_POINTER(srealloc(p226,2););
printStats();
void* p227 = last_address;
DEBUG_PRINT(sfree(p157););
printStats();
PRINT_POINTER(srealloc(p150,176););
printStats();
void* p228 = last_address;
PRINT_POINTER(scalloc(198,100););
printStats();
void* p229 = last_address;
DEBUG_PRINT(sfree(p179););
printStats();
PRINT_POINTER(srealloc(p173,232););
printStats();
void* p230 = last_address;
DEBUG_PRINT(sfree(p210););
printStats();
PRINT_POINTER(srealloc(p218,68););
printStats();
void* p231 = last_address;
PRINT_POINTER(scalloc(84,89););
printStats();
void* p232 = last_address;
PRINT_POINTER(smalloc(32););
printStats();
void* p233 = last_address;
DEBUG_PRINT(sfree(p79););
printStats();
DEBUG_PRINT(sfree(p199););
printStats();
PRINT_POINTER(smalloc(92););
printStats();
void* p234 = last_address;
DEBUG_PRINT(sfree(p205););
printStats();
PRINT_POINTER(scalloc(200,92););
printStats();
void* p235 = last_address;
PRINT_POINTER(scalloc(45,130););
printStats();
void* p236 = last_address;
DEBUG_PRINT(sfree(p139););
printStats();
DEBUG_PRINT(sfree(p213););
printStats();
PRINT_POINTER(smalloc(55););
printStats();
void* p237 = last_address;
PRINT_POINTER(smalloc(134););
printStats();
void* p238 = last_address;
PRINT_POINTER(srealloc(p223,45););
printStats();
void* p239 = last_address;
PRINT_POINTER(scalloc(151,215););
printStats();
void* p240 = last_address;
PRINT_POINTER(scalloc(74,165););
printStats();
void* p241 = last_address;
PRINT_POINTER(srealloc(p230,42););
printStats();
void* p242 = last_address;
DEBUG_PRINT(sfree(p156););
printStats();
PRINT_POINTER(srealloc(p222,178););
printStats();
void* p243 = last_address;
PRINT_POINTER(smalloc(14););
printStats();
void* p244 = last_address;
DEBUG_PRINT(sfree(p165););
printStats();
PRINT_POINTER(srealloc(p201,99););
printStats();
void* p245 = last_address;
PRINT_POINTER(srealloc(p135,4););
printStats();
void* p246 = last_address;
PRINT_POINTER(smalloc(120););
printStats();
void* p247 = last_address;
PRINT_POINTER(srealloc(p126,200););
printStats();
void* p248 = last_address;
PRINT_POINTER(smalloc(94););
printStats();
void* p249 = last_address;
PRINT_POINTER(scalloc(45,108););
printStats();
void* p250 = last_address;
PRINT_POINTER(srealloc(p232,243););
printStats();
void* p251 = last_address;
PRINT_POINTER(scalloc(26,35););
printStats();
void* p252 = last_address;
PRINT_POINTER(srealloc(p214,2););
printStats();
void* p253 = last_address;
DEBUG_PRINT(sfree(p211););
printStats();
PRINT_POINTER(scalloc(42,1););
printStats();
void* p254 = last_address;
PRINT_POINTER(smalloc(41););
printStats();
void* p255 = last_address;
PRINT_POINTER(scalloc(58,6););
printStats();
void* p256 = last_address;
PRINT_POINTER(scalloc(195,207););
printStats();
void* p257 = last_address;
PRINT_POINTER(scalloc(210,69););
printStats();
void* p258 = last_address;
DEBUG_PRINT(sfree(p111););
printStats();
PRINT_POINTER(srealloc(p118,36););
printStats();
void* p259 = last_address;
PRINT_POINTER(scalloc(220,132););
printStats();
void* p260 = last_address;
PRINT_POINTER(scalloc(9,66););
printStats();
void* p261 = last_address;
PRINT_POINTER(smalloc(112););
printStats();
void* p262 = last_address;
PRINT_POINTER(smalloc(120););
printStats();
void* p263 = last_address;
DEBUG_PRINT(sfree(p247););
printStats();
PRINT_POINTER(srealloc(p196,111););
printStats();
void* p264 = last_address;
PRINT_POINTER(srealloc(p182,152););
printStats();
void* p265 = last_address;
DEBUG_PRINT(sfree(p233););
printStats();
PRINT_POINTER(srealloc(p149,85););
printStats();
void* p266 = last_address;
DEBUG_PRINT(sfree(p236););
printStats();
DEBUG_PRINT(sfree(p188););
printStats();
PRINT_POINTER(smalloc(13););
printStats();
void* p267 = last_address;
PRINT_POINTER(scalloc(23,49););
printStats();
void* p268 = last_address;
PRINT_POINTER(srealloc(p257,100););
printStats();
void* p269 = last_address;
PRINT_POINTER(srealloc(p267,209););
printStats();
void* p270 = last_address;
DEBUG_PRINT(sfree(p264););
printStats();
PRINT_POINTER(smalloc(216););
printStats();
void* p271 = last_address;
PRINT_POINTER(smalloc(135););
printStats();
void* p272 = last_address;
PRINT_POINTER(scalloc(244,67););
printStats();
void* p273 = last_address;
PRINT_POINTER(smalloc(99););
printStats();
void* p274 = last_address;
PRINT_POINTER(srealloc(p220,108););
printStats();
void* p275 = last_address;
PRINT_POINTER(srealloc(p206,109););
printStats();
void* p276 = last_address;
PRINT_POINTER(smalloc(135););
printStats();
void* p277 = last_address;
PRINT_POINTER(srealloc(p245,46););
printStats();
void* p278 = last_address;
DEBUG_PRINT(sfree(p274););
printStats();
PRINT_POINTER(scalloc(226,96););
printStats();
void* p279 = last_address;
PRINT_POINTER(srealloc(p178,173););
printStats();
void* p280 = last_address;
PRINT_POINTER(smalloc(188););
printStats();
void* p281 = last_address;
PRINT_POINTER(srealloc(p224,160););
printStats();
void* p282 = last_address;
DEBUG_PRINT(sfree(p235););
printStats();
DEBUG_PRINT(sfree(p133););
printStats();
DEBUG_PRINT(sfree(p229););
printStats();
PRINT_POINTER(srealloc(p240,81););
printStats();
void* p283 = last_address;
PRINT_POINTER(srealloc(p195,196););
printStats();
void* p284 = last_address;
PRINT_POINTER(srealloc(p244,31););
printStats();
void* p285 = last_address;
PRINT_POINTER(scalloc(43,36););
printStats();
void* p286 = last_address;
PRINT_POINTER(scalloc(40,195););
printStats();
void* p287 = last_address;
PRINT_POINTER(smalloc(33););
printStats();
void* p288 = last_address;
PRINT_POINTER(scalloc(33,38););
printStats();
void* p289 = last_address;
DEBUG_PRINT(sfree(p261););
printStats();
PRINT_POINTER(srealloc(p56,160););
printStats();
void* p290 = last_address;
PRINT_POINTER(smalloc(7););
printStats();
void* p291 = last_address;
DEBUG_PRINT(sfree(p251););
printStats();
DEBUG_PRINT(sfree(p250););
printStats();
PRINT_POINTER(smalloc(186););
printStats();
void* p292 = last_address;
PRINT_POINTER(smalloc(1););
printStats();
void* p293 = last_address;
PRINT_POINTER(srealloc(p253,54););
printStats();
void* p294 = last_address;
PRINT_POINTER(smalloc(29););
printStats();
void* p295 = last_address;
PRINT_POINTER(srealloc(p119,33););
printStats();
void* p296 = last_address;
PRINT_POINTER(scalloc(208,152););
printStats();
void* p297 = last_address;
PRINT_POINTER(smalloc(78););
printStats();
void* p298 = last_address;
DEBUG_PRINT(sfree(p297););
printStats();
PRINT_POINTER(scalloc(93,242););
printStats();
void* p299 = last_address;
PRINT_POINTER(srealloc(p275,237););
printStats();
void* p300 = last_address;
PRINT_POINTER(smalloc(79););
printStats();
void* p301 = last_address;
PRINT_POINTER(smalloc(51););
printStats();
void* p302 = last_address;
DEBUG_PRINT(sfree(p289););
printStats();
DEBUG_PRINT(sfree(p189););
printStats();
DEBUG_PRINT(sfree(p125););
printStats();
PRINT_POINTER(scalloc(71,38););
printStats();
void* p303 = last_address;
PRINT_POINTER(smalloc(101););
printStats();
void* p304 = last_address;
DEBUG_PRINT(sfree(p228););
printStats();
PRINT_POINTER(smalloc(107););
printStats();
void* p305 = last_address;
PRINT_POINTER(srealloc(p260,77););
printStats();
void* p306 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p307 = last_address;
DEBUG_PRINT(sfree(p279););
printStats();
DEBUG_PRINT(sfree(p266););
printStats();
PRINT_POINTER(scalloc(55,39););
printStats();
void* p308 = last_address;
PRINT_POINTER(smalloc(84););
printStats();
void* p309 = last_address;
PRINT_POINTER(smalloc(149););
printStats();
void* p310 = last_address;
PRINT_POINTER(scalloc(32,214););
printStats();
void* p311 = last_address;
PRINT_POINTER(scalloc(214,12););
printStats();
void* p312 = last_address;
DEBUG_PRINT(sfree(p239););
printStats();
DEBUG_PRINT(sfree(p184););
printStats();
DEBUG_PRINT(sfree(p171););
printStats();
PRINT_POINTER(srealloc(p268,124););
printStats();
void* p313 = last_address;
DEBUG_PRINT(sfree(p309););
printStats();
PRINT_POINTER(smalloc(3););
printStats();
void* p314 = last_address;
PRINT_POINTER(scalloc(174,35););
printStats();
void* p315 = last_address;
PRINT_POINTER(smalloc(75););
printStats();
void* p316 = last_address;
PRINT_POINTER(smalloc(233););
printStats();
void* p317 = last_address;
PRINT_POINTER(scalloc(200,152););
printStats();
void* p318 = last_address;
DEBUG_PRINT(sfree(p212););
printStats();
DEBUG_PRINT(sfree(p158););
printStats();
PRINT_POINTER(srealloc(p164,196););
printStats();
void* p319 = last_address;
PRINT_POINTER(srealloc(p283,142););
printStats();
void* p320 = last_address;
PRINT_POINTER(srealloc(p290,220););
printStats();
void* p321 = last_address;
PRINT_POINTER(scalloc(207,241););
printStats();
void* p322 = last_address;
PRINT_POINTER(srealloc(p204,9););
printStats();
void* p323 = last_address;
DEBUG_PRINT(sfree(p208););
printStats();
PRINT_POINTER(smalloc(221););
printStats();
void* p324 = last_address;
PRINT_POINTER(scalloc(172,225););
printStats();
void* p325 = last_address;
PRINT_POINTER(smalloc(19););
printStats();
void* p326 = last_address;
PRINT_POINTER(srealloc(p231,230););
printStats();
void* p327 = last_address;
PRINT_POINTER(srealloc(p140,204););
printStats();
void* p328 = last_address;
DEBUG_PRINT(sfree(p319););
printStats();
DEBUG_PRINT(sfree(p132););
printStats();
PRINT_POINTER(smalloc(114););
printStats();
void* p329 = last_address;
PRINT_POINTER(srealloc(p256,74););
printStats();
void* p330 = last_address;
PRINT_POINTER(srealloc(p242,163););
printStats();
void* p331 = last_address;
DEBUG_PRINT(sfree(p305););
printStats();
PRINT_POINTER(smalloc(83););
printStats();
void* p332 = last_address;
PRINT_POINTER(scalloc(170,83););
printStats();
void* p333 = last_address;
DEBUG_PRINT(sfree(p248););
printStats();
PRINT_POINTER(srealloc(p262,155););
printStats();
void* p334 = last_address;
PRINT_POINTER(scalloc(168,244););
printStats();
void* p335 = last_address;
PRINT_POINTER(srealloc(p335,84););
printStats();
void* p336 = last_address;
PRINT_POINTER(srealloc(p84,158););
printStats();
void* p337 = last_address;
PRINT_POINTER(smalloc(122););
printStats();
void* p338 = last_address;
DEBUG_PRINT(sfree(p336););
printStats();
PRINT_POINTER(srealloc(p185,144););
printStats();
void* p339 = last_address;
PRINT_POINTER(smalloc(208););
printStats();
void* p340 = last_address;
DEBUG_PRINT(sfree(p221););
printStats();
DEBUG_PRINT(sfree(p131););
printStats();
PRINT_POINTER(smalloc(96););
printStats();
void* p341 = last_address;
DEBUG_PRINT(sfree(p219););
printStats();
DEBUG_PRINT(sfree(p227););
printStats();
PRINT_POINTER(scalloc(57,115););
printStats();
void* p342 = last_address;
PRINT_POINTER(smalloc(121););
printStats();
void* p343 = last_address;
PRINT_POINTER(scalloc(161,107););
printStats();
void* p344 = last_address;
PRINT_POINTER(scalloc(1,107););
printStats();
void* p345 = last_address;
DEBUG_PRINT(sfree(p345););
printStats();
PRINT_POINTER(scalloc(5,188););
printStats();
void* p346 = last_address;
PRINT_POINTER(scalloc(74,90););
printStats();
void* p347 = last_address;
DEBUG_PRINT(sfree(p293););
printStats();
DEBUG_PRINT(sfree(p301););
printStats();
PRINT_POINTER(srealloc(p322,43););
printStats();
void* p348 = last_address;
PRINT_POINTER(srealloc(p269,146););
printStats();
void* p349 = last_address;
PRINT_POINTER(srealloc(p332,192););
printStats();
void* p350 = last_address;
PRINT_POINTER(srealloc(p276,165););
printStats();
void* p351 = last_address;
PRINT_POINTER(scalloc(149,70););
printStats();
void* p352 = last_address;
PRINT_POINTER(scalloc(151,213););
printStats();
void* p353 = last_address;
PRINT_POINTER(srealloc(p176,60););
printStats();
void* p354 = last_address;
PRINT_POINTER(scalloc(236,62););
printStats();
void* p355 = last_address;
PRINT_POINTER(srealloc(p114,83););
printStats();
void* p356 = last_address;
PRINT_POINTER(smalloc(138););
printStats();
void* p357 = last_address;
}
