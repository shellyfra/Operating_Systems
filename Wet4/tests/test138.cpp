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
                        PRINT_POINTER(scalloc(236,154););
printStats();
void* p0 = last_address;
PRINT_POINTER(srealloc(p0,229););
printStats();
void* p1 = last_address;
PRINT_POINTER(scalloc(111,221););
printStats();
void* p2 = last_address;
PRINT_POINTER(srealloc(p1,211););
printStats();
void* p3 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
PRINT_POINTER(smalloc(247););
printStats();
void* p4 = last_address;
PRINT_POINTER(scalloc(82,154););
printStats();
void* p5 = last_address;
PRINT_POINTER(srealloc(p2,114););
printStats();
void* p6 = last_address;
PRINT_POINTER(srealloc(p5,64););
printStats();
void* p7 = last_address;
PRINT_POINTER(smalloc(186););
printStats();
void* p8 = last_address;
PRINT_POINTER(scalloc(184,133););
printStats();
void* p9 = last_address;
PRINT_POINTER(smalloc(147););
printStats();
void* p10 = last_address;
PRINT_POINTER(smalloc(160););
printStats();
void* p11 = last_address;
DEBUG_PRINT(sfree(p11););
printStats();
PRINT_POINTER(scalloc(1,208););
printStats();
void* p12 = last_address;
PRINT_POINTER(srealloc(p10,174););
printStats();
void* p13 = last_address;
PRINT_POINTER(scalloc(85,181););
printStats();
void* p14 = last_address;
PRINT_POINTER(scalloc(139,102););
printStats();
void* p15 = last_address;
DEBUG_PRINT(sfree(p8););
printStats();
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(smalloc(147););
printStats();
void* p16 = last_address;
PRINT_POINTER(smalloc(33););
printStats();
void* p17 = last_address;
PRINT_POINTER(scalloc(40,74););
printStats();
void* p18 = last_address;
PRINT_POINTER(scalloc(42,244););
printStats();
void* p19 = last_address;
PRINT_POINTER(srealloc(p12,151););
printStats();
void* p20 = last_address;
PRINT_POINTER(srealloc(p18,67););
printStats();
void* p21 = last_address;
PRINT_POINTER(smalloc(43););
printStats();
void* p22 = last_address;
PRINT_POINTER(srealloc(p14,124););
printStats();
void* p23 = last_address;
PRINT_POINTER(smalloc(238););
printStats();
void* p24 = last_address;
PRINT_POINTER(scalloc(28,40););
printStats();
void* p25 = last_address;
PRINT_POINTER(srealloc(p23,127););
printStats();
void* p26 = last_address;
PRINT_POINTER(scalloc(91,75););
printStats();
void* p27 = last_address;
PRINT_POINTER(srealloc(p27,114););
printStats();
void* p28 = last_address;
PRINT_POINTER(scalloc(139,172););
printStats();
void* p29 = last_address;
PRINT_POINTER(srealloc(p16,176););
printStats();
void* p30 = last_address;
PRINT_POINTER(scalloc(87,203););
printStats();
void* p31 = last_address;
DEBUG_PRINT(sfree(p31););
printStats();
PRINT_POINTER(srealloc(p7,166););
printStats();
void* p32 = last_address;
PRINT_POINTER(scalloc(88,191););
printStats();
void* p33 = last_address;
DEBUG_PRINT(sfree(p22););
printStats();
PRINT_POINTER(srealloc(p4,159););
printStats();
void* p34 = last_address;
PRINT_POINTER(srealloc(p9,68););
printStats();
void* p35 = last_address;
PRINT_POINTER(scalloc(127,209););
printStats();
void* p36 = last_address;
DEBUG_PRINT(sfree(p29););
printStats();
PRINT_POINTER(scalloc(169,158););
printStats();
void* p37 = last_address;
PRINT_POINTER(smalloc(86););
printStats();
void* p38 = last_address;
PRINT_POINTER(srealloc(p24,162););
printStats();
void* p39 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p40 = last_address;
PRINT_POINTER(smalloc(187););
printStats();
void* p41 = last_address;
PRINT_POINTER(smalloc(96););
printStats();
void* p42 = last_address;
PRINT_POINTER(smalloc(106););
printStats();
void* p43 = last_address;
PRINT_POINTER(srealloc(p17,55););
printStats();
void* p44 = last_address;
DEBUG_PRINT(sfree(p36););
printStats();
PRINT_POINTER(scalloc(38,78););
printStats();
void* p45 = last_address;
PRINT_POINTER(scalloc(203,213););
printStats();
void* p46 = last_address;
PRINT_POINTER(srealloc(p25,224););
printStats();
void* p47 = last_address;
PRINT_POINTER(smalloc(161););
printStats();
void* p48 = last_address;
PRINT_POINTER(srealloc(p21,145););
printStats();
void* p49 = last_address;
PRINT_POINTER(scalloc(26,235););
printStats();
void* p50 = last_address;
PRINT_POINTER(scalloc(145,246););
printStats();
void* p51 = last_address;
PRINT_POINTER(smalloc(189););
printStats();
void* p52 = last_address;
DEBUG_PRINT(sfree(p43););
printStats();
PRINT_POINTER(scalloc(125,79););
printStats();
void* p53 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
DEBUG_PRINT(sfree(p35););
printStats();
PRINT_POINTER(srealloc(p50,2););
printStats();
void* p54 = last_address;
PRINT_POINTER(smalloc(131););
printStats();
void* p55 = last_address;
PRINT_POINTER(scalloc(185,132););
printStats();
void* p56 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
PRINT_POINTER(scalloc(68,109););
printStats();
void* p57 = last_address;
PRINT_POINTER(scalloc(58,232););
printStats();
void* p58 = last_address;
DEBUG_PRINT(sfree(p53););
printStats();
PRINT_POINTER(scalloc(171,200););
printStats();
void* p59 = last_address;
PRINT_POINTER(srealloc(p13,121););
printStats();
void* p60 = last_address;
PRINT_POINTER(srealloc(p33,167););
printStats();
void* p61 = last_address;
PRINT_POINTER(smalloc(78););
printStats();
void* p62 = last_address;
PRINT_POINTER(srealloc(p56,100););
printStats();
void* p63 = last_address;
PRINT_POINTER(smalloc(203););
printStats();
void* p64 = last_address;
PRINT_POINTER(smalloc(166););
printStats();
void* p65 = last_address;
PRINT_POINTER(smalloc(137););
printStats();
void* p66 = last_address;
DEBUG_PRINT(sfree(p60););
printStats();
PRINT_POINTER(smalloc(198););
printStats();
void* p67 = last_address;
PRINT_POINTER(srealloc(p38,178););
printStats();
void* p68 = last_address;
PRINT_POINTER(scalloc(111,68););
printStats();
void* p69 = last_address;
PRINT_POINTER(smalloc(143););
printStats();
void* p70 = last_address;
PRINT_POINTER(srealloc(p20,132););
printStats();
void* p71 = last_address;
PRINT_POINTER(smalloc(146););
printStats();
void* p72 = last_address;
DEBUG_PRINT(sfree(p67););
printStats();
PRINT_POINTER(srealloc(p47,63););
printStats();
void* p73 = last_address;
PRINT_POINTER(srealloc(p58,54););
printStats();
void* p74 = last_address;
PRINT_POINTER(scalloc(231,249););
printStats();
void* p75 = last_address;
PRINT_POINTER(smalloc(155););
printStats();
void* p76 = last_address;
PRINT_POINTER(scalloc(141,184););
printStats();
void* p77 = last_address;
PRINT_POINTER(scalloc(5,133););
printStats();
void* p78 = last_address;
PRINT_POINTER(scalloc(1,229););
printStats();
void* p79 = last_address;
PRINT_POINTER(srealloc(p71,33););
printStats();
void* p80 = last_address;
DEBUG_PRINT(sfree(p51););
printStats();
PRINT_POINTER(smalloc(184););
printStats();
void* p81 = last_address;
PRINT_POINTER(smalloc(171););
printStats();
void* p82 = last_address;
DEBUG_PRINT(sfree(p82););
printStats();
PRINT_POINTER(smalloc(14););
printStats();
void* p83 = last_address;
DEBUG_PRINT(sfree(p68););
printStats();
PRINT_POINTER(smalloc(133););
printStats();
void* p84 = last_address;
PRINT_POINTER(smalloc(147););
printStats();
void* p85 = last_address;
PRINT_POINTER(srealloc(p54,90););
printStats();
void* p86 = last_address;
PRINT_POINTER(srealloc(p44,206););
printStats();
void* p87 = last_address;
DEBUG_PRINT(sfree(p62););
printStats();
DEBUG_PRINT(sfree(p41););
printStats();
PRINT_POINTER(smalloc(248););
printStats();
void* p88 = last_address;
PRINT_POINTER(srealloc(p70,13););
printStats();
void* p89 = last_address;
PRINT_POINTER(smalloc(188););
printStats();
void* p90 = last_address;
PRINT_POINTER(scalloc(107,63););
printStats();
void* p91 = last_address;
PRINT_POINTER(srealloc(p64,75););
printStats();
void* p92 = last_address;
PRINT_POINTER(smalloc(32););
printStats();
void* p93 = last_address;
PRINT_POINTER(smalloc(98););
printStats();
void* p94 = last_address;
PRINT_POINTER(scalloc(187,16););
printStats();
void* p95 = last_address;
PRINT_POINTER(smalloc(121););
printStats();
void* p96 = last_address;
PRINT_POINTER(scalloc(224,107););
printStats();
void* p97 = last_address;
PRINT_POINTER(srealloc(p59,13););
printStats();
void* p98 = last_address;
DEBUG_PRINT(sfree(p98););
printStats();
PRINT_POINTER(scalloc(150,226););
printStats();
void* p99 = last_address;
DEBUG_PRINT(sfree(p80););
printStats();
DEBUG_PRINT(sfree(p57););
printStats();
PRINT_POINTER(srealloc(p15,170););
printStats();
void* p100 = last_address;
DEBUG_PRINT(sfree(p93););
printStats();
PRINT_POINTER(smalloc(219););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(25););
printStats();
void* p102 = last_address;
PRINT_POINTER(smalloc(30););
printStats();
void* p103 = last_address;
PRINT_POINTER(srealloc(p32,107););
printStats();
void* p104 = last_address;
PRINT_POINTER(srealloc(p90,191););
printStats();
void* p105 = last_address;
PRINT_POINTER(smalloc(144););
printStats();
void* p106 = last_address;
PRINT_POINTER(srealloc(p92,37););
printStats();
void* p107 = last_address;
PRINT_POINTER(srealloc(p96,175););
printStats();
void* p108 = last_address;
PRINT_POINTER(scalloc(108,198););
printStats();
void* p109 = last_address;
DEBUG_PRINT(sfree(p83););
printStats();
PRINT_POINTER(srealloc(p86,63););
printStats();
void* p110 = last_address;
DEBUG_PRINT(sfree(p97););
printStats();
PRINT_POINTER(scalloc(16,37););
printStats();
void* p111 = last_address;
PRINT_POINTER(scalloc(96,131););
printStats();
void* p112 = last_address;
DEBUG_PRINT(sfree(p66););
printStats();
PRINT_POINTER(scalloc(56,116););
printStats();
void* p113 = last_address;
PRINT_POINTER(srealloc(p85,202););
printStats();
void* p114 = last_address;
DEBUG_PRINT(sfree(p39););
printStats();
PRINT_POINTER(srealloc(p26,71););
printStats();
void* p115 = last_address;
PRINT_POINTER(srealloc(p84,116););
printStats();
void* p116 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
PRINT_POINTER(scalloc(167,21););
printStats();
void* p117 = last_address;
PRINT_POINTER(smalloc(132););
printStats();
void* p118 = last_address;
PRINT_POINTER(srealloc(p88,83););
printStats();
void* p119 = last_address;
PRINT_POINTER(smalloc(170););
printStats();
void* p120 = last_address;
PRINT_POINTER(scalloc(167,154););
printStats();
void* p121 = last_address;
DEBUG_PRINT(sfree(p52););
printStats();
PRINT_POINTER(smalloc(226););
printStats();
void* p122 = last_address;
DEBUG_PRINT(sfree(p42););
printStats();
PRINT_POINTER(srealloc(p69,181););
printStats();
void* p123 = last_address;
DEBUG_PRINT(sfree(p123););
printStats();
PRINT_POINTER(smalloc(108););
printStats();
void* p124 = last_address;
DEBUG_PRINT(sfree(p103););
printStats();
DEBUG_PRINT(sfree(p73););
printStats();
PRINT_POINTER(smalloc(202););
printStats();
void* p125 = last_address;
PRINT_POINTER(smalloc(233););
printStats();
void* p126 = last_address;
DEBUG_PRINT(sfree(p111););
printStats();
PRINT_POINTER(scalloc(171,198););
printStats();
void* p127 = last_address;
DEBUG_PRINT(sfree(p113););
printStats();
PRINT_POINTER(smalloc(121););
printStats();
void* p128 = last_address;
DEBUG_PRINT(sfree(p91););
printStats();
PRINT_POINTER(smalloc(129););
printStats();
void* p129 = last_address;
PRINT_POINTER(srealloc(p121,55););
printStats();
void* p130 = last_address;
PRINT_POINTER(srealloc(p110,86););
printStats();
void* p131 = last_address;
PRINT_POINTER(scalloc(245,167););
printStats();
void* p132 = last_address;
DEBUG_PRINT(sfree(p40););
printStats();
PRINT_POINTER(smalloc(24););
printStats();
void* p133 = last_address;
PRINT_POINTER(srealloc(p129,91););
printStats();
void* p134 = last_address;
DEBUG_PRINT(sfree(p99););
printStats();
PRINT_POINTER(srealloc(p104,171););
printStats();
void* p135 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
PRINT_POINTER(srealloc(p72,6););
printStats();
void* p136 = last_address;
PRINT_POINTER(scalloc(208,25););
printStats();
void* p137 = last_address;
PRINT_POINTER(smalloc(244););
printStats();
void* p138 = last_address;
PRINT_POINTER(srealloc(p131,228););
printStats();
void* p139 = last_address;
PRINT_POINTER(smalloc(184););
printStats();
void* p140 = last_address;
PRINT_POINTER(srealloc(p112,141););
printStats();
void* p141 = last_address;
PRINT_POINTER(scalloc(206,237););
printStats();
void* p142 = last_address;
PRINT_POINTER(smalloc(227););
printStats();
void* p143 = last_address;
PRINT_POINTER(scalloc(150,174););
printStats();
void* p144 = last_address;
PRINT_POINTER(smalloc(201););
printStats();
void* p145 = last_address;
DEBUG_PRINT(sfree(p109););
printStats();
PRINT_POINTER(scalloc(218,173););
printStats();
void* p146 = last_address;
DEBUG_PRINT(sfree(p133););
printStats();
PRINT_POINTER(scalloc(149,122););
printStats();
void* p147 = last_address;
PRINT_POINTER(srealloc(p45,126););
printStats();
void* p148 = last_address;
DEBUG_PRINT(sfree(p106););
printStats();
DEBUG_PRINT(sfree(p119););
printStats();
PRINT_POINTER(smalloc(46););
printStats();
void* p149 = last_address;
PRINT_POINTER(scalloc(45,154););
printStats();
void* p150 = last_address;
PRINT_POINTER(scalloc(218,24););
printStats();
void* p151 = last_address;
PRINT_POINTER(srealloc(p136,196););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p87,153););
printStats();
void* p153 = last_address;
PRINT_POINTER(scalloc(4,7););
printStats();
void* p154 = last_address;
PRINT_POINTER(scalloc(188,132););
printStats();
void* p155 = last_address;
PRINT_POINTER(srealloc(p74,19););
printStats();
void* p156 = last_address;
PRINT_POINTER(scalloc(92,37););
printStats();
void* p157 = last_address;
PRINT_POINTER(smalloc(228););
printStats();
void* p158 = last_address;
PRINT_POINTER(scalloc(80,17););
printStats();
void* p159 = last_address;
DEBUG_PRINT(sfree(p48););
printStats();
DEBUG_PRINT(sfree(p115););
printStats();
PRINT_POINTER(srealloc(p147,155););
printStats();
void* p160 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p161 = last_address;
PRINT_POINTER(srealloc(p148,3););
printStats();
void* p162 = last_address;
PRINT_POINTER(smalloc(242););
printStats();
void* p163 = last_address;
DEBUG_PRINT(sfree(p105););
printStats();
DEBUG_PRINT(sfree(p107););
printStats();
PRINT_POINTER(smalloc(119););
printStats();
void* p164 = last_address;
PRINT_POINTER(srealloc(p143,75););
printStats();
void* p165 = last_address;
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(smalloc(6););
printStats();
void* p166 = last_address;
DEBUG_PRINT(sfree(p127););
printStats();
PRINT_POINTER(scalloc(239,180););
printStats();
void* p167 = last_address;
PRINT_POINTER(scalloc(165,1););
printStats();
void* p168 = last_address;
PRINT_POINTER(scalloc(125,59););
printStats();
void* p169 = last_address;
DEBUG_PRINT(sfree(p94););
printStats();
PRINT_POINTER(scalloc(46,179););
printStats();
void* p170 = last_address;
DEBUG_PRINT(sfree(p164););
printStats();
PRINT_POINTER(smalloc(244););
printStats();
void* p171 = last_address;
PRINT_POINTER(scalloc(142,207););
printStats();
void* p172 = last_address;
PRINT_POINTER(smalloc(148););
printStats();
void* p173 = last_address;
PRINT_POINTER(scalloc(210,132););
printStats();
void* p174 = last_address;
PRINT_POINTER(smalloc(195););
printStats();
void* p175 = last_address;
DEBUG_PRINT(sfree(p118););
printStats();
PRINT_POINTER(scalloc(190,202););
printStats();
void* p176 = last_address;
PRINT_POINTER(srealloc(p151,153););
printStats();
void* p177 = last_address;
PRINT_POINTER(smalloc(164););
printStats();
void* p178 = last_address;
PRINT_POINTER(scalloc(241,78););
printStats();
void* p179 = last_address;
DEBUG_PRINT(sfree(p153););
printStats();
PRINT_POINTER(srealloc(p169,17););
printStats();
void* p180 = last_address;
PRINT_POINTER(scalloc(238,85););
printStats();
void* p181 = last_address;
DEBUG_PRINT(sfree(p175););
printStats();
PRINT_POINTER(smalloc(143););
printStats();
void* p182 = last_address;
PRINT_POINTER(smalloc(159););
printStats();
void* p183 = last_address;
PRINT_POINTER(smalloc(91););
printStats();
void* p184 = last_address;
PRINT_POINTER(scalloc(128,32););
printStats();
void* p185 = last_address;
DEBUG_PRINT(sfree(p161););
printStats();
PRINT_POINTER(srealloc(p179,102););
printStats();
void* p186 = last_address;
PRINT_POINTER(scalloc(149,126););
printStats();
void* p187 = last_address;
PRINT_POINTER(smalloc(85););
printStats();
void* p188 = last_address;
DEBUG_PRINT(sfree(p142););
printStats();
PRINT_POINTER(srealloc(p141,63););
printStats();
void* p189 = last_address;
PRINT_POINTER(smalloc(136););
printStats();
void* p190 = last_address;
PRINT_POINTER(smalloc(116););
printStats();
void* p191 = last_address;
DEBUG_PRINT(sfree(p81););
printStats();
PRINT_POINTER(smalloc(109););
printStats();
void* p192 = last_address;
DEBUG_PRINT(sfree(p138););
printStats();
PRINT_POINTER(scalloc(46,141););
printStats();
void* p193 = last_address;
PRINT_POINTER(smalloc(102););
printStats();
void* p194 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p195 = last_address;
PRINT_POINTER(smalloc(76););
printStats();
void* p196 = last_address;
PRINT_POINTER(smalloc(152););
printStats();
void* p197 = last_address;
PRINT_POINTER(smalloc(180););
printStats();
void* p198 = last_address;
PRINT_POINTER(smalloc(93););
printStats();
void* p199 = last_address;
PRINT_POINTER(scalloc(212,216););
printStats();
void* p200 = last_address;
PRINT_POINTER(smalloc(37););
printStats();
void* p201 = last_address;
PRINT_POINTER(scalloc(147,22););
printStats();
void* p202 = last_address;
DEBUG_PRINT(sfree(p168););
printStats();
PRINT_POINTER(srealloc(p124,237););
printStats();
void* p203 = last_address;
PRINT_POINTER(srealloc(p200,188););
printStats();
void* p204 = last_address;
PRINT_POINTER(scalloc(178,123););
printStats();
void* p205 = last_address;
PRINT_POINTER(smalloc(69););
printStats();
void* p206 = last_address;
PRINT_POINTER(smalloc(115););
printStats();
void* p207 = last_address;
PRINT_POINTER(srealloc(p76,51););
printStats();
void* p208 = last_address;
PRINT_POINTER(scalloc(57,106););
printStats();
void* p209 = last_address;
PRINT_POINTER(srealloc(p192,205););
printStats();
void* p210 = last_address;
DEBUG_PRINT(sfree(p77););
printStats();
PRINT_POINTER(scalloc(81,69););
printStats();
void* p211 = last_address;
PRINT_POINTER(scalloc(186,3););
printStats();
void* p212 = last_address;
PRINT_POINTER(srealloc(p78,144););
printStats();
void* p213 = last_address;
PRINT_POINTER(scalloc(183,241););
printStats();
void* p214 = last_address;
PRINT_POINTER(srealloc(p154,87););
printStats();
void* p215 = last_address;
PRINT_POINTER(scalloc(84,123););
printStats();
void* p216 = last_address;
PRINT_POINTER(smalloc(241););
printStats();
void* p217 = last_address;
PRINT_POINTER(smalloc(110););
printStats();
void* p218 = last_address;
PRINT_POINTER(scalloc(47,226););
printStats();
void* p219 = last_address;
DEBUG_PRINT(sfree(p63););
printStats();
PRINT_POINTER(scalloc(166,85););
printStats();
void* p220 = last_address;
DEBUG_PRINT(sfree(p207););
printStats();
PRINT_POINTER(scalloc(214,110););
printStats();
void* p221 = last_address;
PRINT_POINTER(srealloc(p166,208););
printStats();
void* p222 = last_address;
DEBUG_PRINT(sfree(p170););
printStats();
PRINT_POINTER(scalloc(45,113););
printStats();
void* p223 = last_address;
PRINT_POINTER(smalloc(235););
printStats();
void* p224 = last_address;
PRINT_POINTER(smalloc(130););
printStats();
void* p225 = last_address;
DEBUG_PRINT(sfree(p214););
printStats();
PRINT_POINTER(smalloc(76););
printStats();
void* p226 = last_address;
PRINT_POINTER(scalloc(148,6););
printStats();
void* p227 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p228 = last_address;
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(srealloc(p209,238););
printStats();
void* p229 = last_address;
PRINT_POINTER(scalloc(108,58););
printStats();
void* p230 = last_address;
PRINT_POINTER(srealloc(p219,169););
printStats();
void* p231 = last_address;
DEBUG_PRINT(sfree(p228););
printStats();
PRINT_POINTER(srealloc(p212,126););
printStats();
void* p232 = last_address;
PRINT_POINTER(srealloc(p202,130););
printStats();
void* p233 = last_address;
DEBUG_PRINT(sfree(p233););
printStats();
PRINT_POINTER(scalloc(61,193););
printStats();
void* p234 = last_address;
PRINT_POINTER(scalloc(27,120););
printStats();
void* p235 = last_address;
PRINT_POINTER(srealloc(p37,126););
printStats();
void* p236 = last_address;
PRINT_POINTER(scalloc(65,214););
printStats();
void* p237 = last_address;
PRINT_POINTER(srealloc(p199,96););
printStats();
void* p238 = last_address;
PRINT_POINTER(scalloc(39,131););
printStats();
void* p239 = last_address;
PRINT_POINTER(smalloc(186););
printStats();
void* p240 = last_address;
PRINT_POINTER(smalloc(109););
printStats();
void* p241 = last_address;
PRINT_POINTER(smalloc(112););
printStats();
void* p242 = last_address;
PRINT_POINTER(srealloc(p241,40););
printStats();
void* p243 = last_address;
PRINT_POINTER(scalloc(200,195););
printStats();
void* p244 = last_address;
DEBUG_PRINT(sfree(p182););
printStats();
PRINT_POINTER(smalloc(216););
printStats();
void* p245 = last_address;
PRINT_POINTER(srealloc(p226,189););
printStats();
void* p246 = last_address;
PRINT_POINTER(scalloc(211,211););
printStats();
void* p247 = last_address;
DEBUG_PRINT(sfree(p132););
printStats();
PRINT_POINTER(smalloc(155););
printStats();
void* p248 = last_address;
PRINT_POINTER(scalloc(242,93););
printStats();
void* p249 = last_address;
PRINT_POINTER(smalloc(110););
printStats();
void* p250 = last_address;
PRINT_POINTER(smalloc(92););
printStats();
void* p251 = last_address;
PRINT_POINTER(smalloc(101););
printStats();
void* p252 = last_address;
PRINT_POINTER(smalloc(192););
printStats();
void* p253 = last_address;
DEBUG_PRINT(sfree(p130););
printStats();
PRINT_POINTER(scalloc(181,30););
printStats();
void* p254 = last_address;
PRINT_POINTER(scalloc(63,58););
printStats();
void* p255 = last_address;
PRINT_POINTER(srealloc(p176,189););
printStats();
void* p256 = last_address;
DEBUG_PRINT(sfree(p222););
printStats();
PRINT_POINTER(smalloc(136););
printStats();
void* p257 = last_address;
PRINT_POINTER(srealloc(p231,170););
printStats();
void* p258 = last_address;
PRINT_POINTER(scalloc(214,4););
printStats();
void* p259 = last_address;
PRINT_POINTER(scalloc(110,8););
printStats();
void* p260 = last_address;
PRINT_POINTER(srealloc(p208,33););
printStats();
void* p261 = last_address;
DEBUG_PRINT(sfree(p205););
printStats();
PRINT_POINTER(scalloc(158,24););
printStats();
void* p262 = last_address;
DEBUG_PRINT(sfree(p108););
printStats();
PRINT_POINTER(srealloc(p218,108););
printStats();
void* p263 = last_address;
PRINT_POINTER(srealloc(p230,131););
printStats();
void* p264 = last_address;
PRINT_POINTER(srealloc(p261,94););
printStats();
void* p265 = last_address;
PRINT_POINTER(smalloc(165););
printStats();
void* p266 = last_address;
PRINT_POINTER(smalloc(162););
printStats();
void* p267 = last_address;
DEBUG_PRINT(sfree(p255););
printStats();
PRINT_POINTER(srealloc(p210,133););
printStats();
void* p268 = last_address;
PRINT_POINTER(smalloc(76););
printStats();
void* p269 = last_address;
DEBUG_PRINT(sfree(p203););
printStats();
PRINT_POINTER(srealloc(p158,0););
printStats();
void* p270 = last_address;
PRINT_POINTER(srealloc(p137,101););
printStats();
void* p271 = last_address;
PRINT_POINTER(srealloc(p163,194););
printStats();
void* p272 = last_address;
PRINT_POINTER(srealloc(p253,156););
printStats();
void* p273 = last_address;
PRINT_POINTER(scalloc(222,28););
printStats();
void* p274 = last_address;
PRINT_POINTER(smalloc(239););
printStats();
void* p275 = last_address;
PRINT_POINTER(srealloc(p149,12););
printStats();
void* p276 = last_address;
DEBUG_PRINT(sfree(p150););
printStats();
PRINT_POINTER(scalloc(129,240););
printStats();
void* p277 = last_address;
PRINT_POINTER(smalloc(237););
printStats();
void* p278 = last_address;
DEBUG_PRINT(sfree(p257););
printStats();
PRINT_POINTER(smalloc(240););
printStats();
void* p279 = last_address;
PRINT_POINTER(srealloc(p178,27););
printStats();
void* p280 = last_address;
DEBUG_PRINT(sfree(p126););
printStats();
PRINT_POINTER(srealloc(p152,85););
printStats();
void* p281 = last_address;
PRINT_POINTER(smalloc(83););
printStats();
void* p282 = last_address;
PRINT_POINTER(smalloc(109););
printStats();
void* p283 = last_address;
PRINT_POINTER(smalloc(90););
printStats();
void* p284 = last_address;
PRINT_POINTER(smalloc(124););
printStats();
void* p285 = last_address;
PRINT_POINTER(smalloc(136););
printStats();
void* p286 = last_address;
PRINT_POINTER(scalloc(144,98););
printStats();
void* p287 = last_address;
PRINT_POINTER(smalloc(175););
printStats();
void* p288 = last_address;
PRINT_POINTER(srealloc(p217,229););
printStats();
void* p289 = last_address;
PRINT_POINTER(scalloc(135,242););
printStats();
void* p290 = last_address;
PRINT_POINTER(scalloc(173,121););
printStats();
void* p291 = last_address;
PRINT_POINTER(srealloc(p251,56););
printStats();
void* p292 = last_address;
PRINT_POINTER(scalloc(78,243););
printStats();
void* p293 = last_address;
DEBUG_PRINT(sfree(p206););
printStats();
PRINT_POINTER(srealloc(p193,249););
printStats();
void* p294 = last_address;
PRINT_POINTER(srealloc(p281,198););
printStats();
void* p295 = last_address;
PRINT_POINTER(scalloc(39,234););
printStats();
void* p296 = last_address;
PRINT_POINTER(srealloc(p290,99););
printStats();
void* p297 = last_address;
PRINT_POINTER(scalloc(129,141););
printStats();
void* p298 = last_address;
PRINT_POINTER(srealloc(p247,126););
printStats();
void* p299 = last_address;
PRINT_POINTER(scalloc(55,43););
printStats();
void* p300 = last_address;
PRINT_POINTER(srealloc(p190,192););
printStats();
void* p301 = last_address;
PRINT_POINTER(srealloc(p240,189););
printStats();
void* p302 = last_address;
PRINT_POINTER(scalloc(33,185););
printStats();
void* p303 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p304 = last_address;
PRINT_POINTER(srealloc(p30,210););
printStats();
void* p305 = last_address;
DEBUG_PRINT(sfree(p117););
printStats();
DEBUG_PRINT(sfree(p268););
printStats();
PRINT_POINTER(srealloc(p238,81););
printStats();
void* p306 = last_address;
PRINT_POINTER(srealloc(p172,128););
printStats();
void* p307 = last_address;
PRINT_POINTER(scalloc(36,40););
printStats();
void* p308 = last_address;
PRINT_POINTER(smalloc(173););
printStats();
void* p309 = last_address;
PRINT_POINTER(srealloc(p284,143););
printStats();
void* p310 = last_address;
PRINT_POINTER(srealloc(p183,15););
printStats();
void* p311 = last_address;
PRINT_POINTER(smalloc(56););
printStats();
void* p312 = last_address;
PRINT_POINTER(smalloc(76););
printStats();
void* p313 = last_address;
PRINT_POINTER(smalloc(17););
printStats();
void* p314 = last_address;
}
