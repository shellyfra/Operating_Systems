#include "aux_macro.h"
#include "../malloc_4.cpp"
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
                        PRINT_POINTER(smalloc(71););
printStats();
void* p0 = last_address;
DEBUG_PRINT(sfree(p0););
printStats();
PRINT_POINTER(smalloc(214););
printStats();
void* p1 = last_address;
PRINT_POINTER(scalloc(157,164););
printStats();
void* p2 = last_address;
PRINT_POINTER(smalloc(185););
printStats();
void* p3 = last_address;
PRINT_POINTER(srealloc(p2,48););
printStats();
void* p4 = last_address;
PRINT_POINTER(scalloc(152,16););
printStats();
void* p5 = last_address;
PRINT_POINTER(srealloc(p1,96););
printStats();
void* p6 = last_address;
PRINT_POINTER(scalloc(140,61););
printStats();
void* p7 = last_address;
DEBUG_PRINT(sfree(p6););
printStats();
PRINT_POINTER(scalloc(18,49););
printStats();
void* p8 = last_address;
DEBUG_PRINT(sfree(p3););
printStats();
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(scalloc(246,210););
printStats();
void* p9 = last_address;
PRINT_POINTER(smalloc(135););
printStats();
void* p10 = last_address;
PRINT_POINTER(scalloc(133,225););
printStats();
void* p11 = last_address;
PRINT_POINTER(smalloc(101););
printStats();
void* p12 = last_address;
PRINT_POINTER(srealloc(p8,97););
printStats();
void* p13 = last_address;
DEBUG_PRINT(sfree(p12););
printStats();
PRINT_POINTER(srealloc(p9,166););
printStats();
void* p14 = last_address;
PRINT_POINTER(smalloc(231););
printStats();
void* p15 = last_address;
DEBUG_PRINT(sfree(p5););
printStats();
DEBUG_PRINT(sfree(p15););
printStats();
PRINT_POINTER(smalloc(248););
printStats();
void* p16 = last_address;
PRINT_POINTER(smalloc(238););
printStats();
void* p17 = last_address;
DEBUG_PRINT(sfree(p11););
printStats();
DEBUG_PRINT(sfree(p14););
printStats();
PRINT_POINTER(scalloc(163,57););
printStats();
void* p18 = last_address;
PRINT_POINTER(srealloc(p13,59););
printStats();
void* p19 = last_address;
PRINT_POINTER(smalloc(189););
printStats();
void* p20 = last_address;
DEBUG_PRINT(sfree(p7););
printStats();
PRINT_POINTER(scalloc(214,239););
printStats();
void* p21 = last_address;
DEBUG_PRINT(sfree(p18););
printStats();
DEBUG_PRINT(sfree(p17););
printStats();
PRINT_POINTER(scalloc(174,25););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p21););
printStats();
PRINT_POINTER(scalloc(85,30););
printStats();
void* p23 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(srealloc(p16,145););
printStats();
void* p24 = last_address;
PRINT_POINTER(smalloc(183););
printStats();
void* p25 = last_address;
PRINT_POINTER(srealloc(p25,10););
printStats();
void* p26 = last_address;
PRINT_POINTER(srealloc(p24,65););
printStats();
void* p27 = last_address;
PRINT_POINTER(scalloc(65,148););
printStats();
void* p28 = last_address;
PRINT_POINTER(scalloc(234,152););
printStats();
void* p29 = last_address;
PRINT_POINTER(srealloc(p10,223););
printStats();
void* p30 = last_address;
PRINT_POINTER(smalloc(123););
printStats();
void* p31 = last_address;
PRINT_POINTER(smalloc(136););
printStats();
void* p32 = last_address;
PRINT_POINTER(scalloc(147,191););
printStats();
void* p33 = last_address;
PRINT_POINTER(srealloc(p27,78););
printStats();
void* p34 = last_address;
DEBUG_PRINT(sfree(p29););
printStats();
PRINT_POINTER(scalloc(66,131););
printStats();
void* p35 = last_address;
PRINT_POINTER(scalloc(101,5););
printStats();
void* p36 = last_address;
PRINT_POINTER(srealloc(p26,244););
printStats();
void* p37 = last_address;
DEBUG_PRINT(sfree(p35););
printStats();
PRINT_POINTER(smalloc(36););
printStats();
void* p38 = last_address;
DEBUG_PRINT(sfree(p31););
printStats();
PRINT_POINTER(srealloc(p33,223););
printStats();
void* p39 = last_address;
PRINT_POINTER(srealloc(p34,29););
printStats();
void* p40 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p41 = last_address;
PRINT_POINTER(smalloc(11););
printStats();
void* p42 = last_address;
PRINT_POINTER(smalloc(169););
printStats();
void* p43 = last_address;
PRINT_POINTER(smalloc(194););
printStats();
void* p44 = last_address;
PRINT_POINTER(scalloc(147,105););
printStats();
void* p45 = last_address;
DEBUG_PRINT(sfree(p42););
printStats();
PRINT_POINTER(smalloc(248););
printStats();
void* p46 = last_address;
PRINT_POINTER(smalloc(212););
printStats();
void* p47 = last_address;
PRINT_POINTER(srealloc(p40,22););
printStats();
void* p48 = last_address;
PRINT_POINTER(srealloc(p47,59););
printStats();
void* p49 = last_address;
PRINT_POINTER(srealloc(p22,99););
printStats();
void* p50 = last_address;
PRINT_POINTER(scalloc(37,64););
printStats();
void* p51 = last_address;
PRINT_POINTER(smalloc(139););
printStats();
void* p52 = last_address;
PRINT_POINTER(srealloc(p36,88););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(102,118););
printStats();
void* p54 = last_address;
PRINT_POINTER(scalloc(92,85););
printStats();
void* p55 = last_address;
PRINT_POINTER(scalloc(134,177););
printStats();
void* p56 = last_address;
PRINT_POINTER(scalloc(84,57););
printStats();
void* p57 = last_address;
PRINT_POINTER(scalloc(232,110););
printStats();
void* p58 = last_address;
PRINT_POINTER(scalloc(181,89););
printStats();
void* p59 = last_address;
PRINT_POINTER(smalloc(133););
printStats();
void* p60 = last_address;
PRINT_POINTER(scalloc(47,153););
printStats();
void* p61 = last_address;
PRINT_POINTER(scalloc(228,158););
printStats();
void* p62 = last_address;
PRINT_POINTER(smalloc(248););
printStats();
void* p63 = last_address;
PRINT_POINTER(srealloc(p32,7););
printStats();
void* p64 = last_address;
DEBUG_PRINT(sfree(p53););
printStats();
PRINT_POINTER(scalloc(192,146););
printStats();
void* p65 = last_address;
PRINT_POINTER(srealloc(p46,40););
printStats();
void* p66 = last_address;
PRINT_POINTER(smalloc(150););
printStats();
void* p67 = last_address;
PRINT_POINTER(smalloc(50););
printStats();
void* p68 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
DEBUG_PRINT(sfree(p20););
printStats();
PRINT_POINTER(srealloc(p60,204););
printStats();
void* p69 = last_address;
PRINT_POINTER(scalloc(50,112););
printStats();
void* p70 = last_address;
PRINT_POINTER(srealloc(p68,16););
printStats();
void* p71 = last_address;
DEBUG_PRINT(sfree(p38););
printStats();
PRINT_POINTER(srealloc(p63,36););
printStats();
void* p72 = last_address;
PRINT_POINTER(scalloc(4,142););
printStats();
void* p73 = last_address;
PRINT_POINTER(scalloc(124,159););
printStats();
void* p74 = last_address;
DEBUG_PRINT(sfree(p39););
printStats();
DEBUG_PRINT(sfree(p70););
printStats();
PRINT_POINTER(scalloc(48,221););
printStats();
void* p75 = last_address;
DEBUG_PRINT(sfree(p48););
printStats();
DEBUG_PRINT(sfree(p64););
printStats();
DEBUG_PRINT(sfree(p19););
printStats();
PRINT_POINTER(srealloc(p62,71););
printStats();
void* p76 = last_address;
PRINT_POINTER(srealloc(p67,207););
printStats();
void* p77 = last_address;
PRINT_POINTER(scalloc(214,126););
printStats();
void* p78 = last_address;
PRINT_POINTER(srealloc(p73,108););
printStats();
void* p79 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
PRINT_POINTER(smalloc(27););
printStats();
void* p80 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p81 = last_address;
PRINT_POINTER(srealloc(p79,66););
printStats();
void* p82 = last_address;
PRINT_POINTER(smalloc(99););
printStats();
void* p83 = last_address;
DEBUG_PRINT(sfree(p83););
printStats();
PRINT_POINTER(smalloc(2););
printStats();
void* p84 = last_address;
PRINT_POINTER(srealloc(p76,162););
printStats();
void* p85 = last_address;
PRINT_POINTER(smalloc(31););
printStats();
void* p86 = last_address;
PRINT_POINTER(smalloc(131););
printStats();
void* p87 = last_address;
PRINT_POINTER(smalloc(127););
printStats();
void* p88 = last_address;
PRINT_POINTER(smalloc(79););
printStats();
void* p89 = last_address;
DEBUG_PRINT(sfree(p59););
printStats();
PRINT_POINTER(smalloc(194););
printStats();
void* p90 = last_address;
PRINT_POINTER(scalloc(113,15););
printStats();
void* p91 = last_address;
PRINT_POINTER(scalloc(116,191););
printStats();
void* p92 = last_address;
DEBUG_PRINT(sfree(p86););
printStats();
PRINT_POINTER(smalloc(88););
printStats();
void* p93 = last_address;
DEBUG_PRINT(sfree(p28););
printStats();
PRINT_POINTER(srealloc(p69,60););
printStats();
void* p94 = last_address;
PRINT_POINTER(scalloc(182,166););
printStats();
void* p95 = last_address;
DEBUG_PRINT(sfree(p89););
printStats();
PRINT_POINTER(smalloc(213););
printStats();
void* p96 = last_address;
PRINT_POINTER(srealloc(p82,48););
printStats();
void* p97 = last_address;
PRINT_POINTER(scalloc(70,148););
printStats();
void* p98 = last_address;
DEBUG_PRINT(sfree(p92););
printStats();
DEBUG_PRINT(sfree(p54););
printStats();
DEBUG_PRINT(sfree(p72););
printStats();
PRINT_POINTER(srealloc(p97,198););
printStats();
void* p99 = last_address;
PRINT_POINTER(srealloc(p80,60););
printStats();
void* p100 = last_address;
DEBUG_PRINT(sfree(p100););
printStats();
PRINT_POINTER(srealloc(p88,36););
printStats();
void* p101 = last_address;
PRINT_POINTER(smalloc(195););
printStats();
void* p102 = last_address;
PRINT_POINTER(srealloc(p56,193););
printStats();
void* p103 = last_address;
PRINT_POINTER(srealloc(p45,152););
printStats();
void* p104 = last_address;
PRINT_POINTER(scalloc(179,140););
printStats();
void* p105 = last_address;
DEBUG_PRINT(sfree(p71););
printStats();
PRINT_POINTER(smalloc(32););
printStats();
void* p106 = last_address;
PRINT_POINTER(scalloc(47,230););
printStats();
void* p107 = last_address;
PRINT_POINTER(scalloc(137,180););
printStats();
void* p108 = last_address;
PRINT_POINTER(smalloc(65););
printStats();
void* p109 = last_address;
DEBUG_PRINT(sfree(p65););
printStats();
PRINT_POINTER(srealloc(p51,14););
printStats();
void* p110 = last_address;
PRINT_POINTER(srealloc(p41,21););
printStats();
void* p111 = last_address;
PRINT_POINTER(scalloc(223,130););
printStats();
void* p112 = last_address;
DEBUG_PRINT(sfree(p94););
printStats();
PRINT_POINTER(srealloc(p77,32););
printStats();
void* p113 = last_address;
PRINT_POINTER(smalloc(159););
printStats();
void* p114 = last_address;
PRINT_POINTER(srealloc(p93,191););
printStats();
void* p115 = last_address;
PRINT_POINTER(smalloc(27););
printStats();
void* p116 = last_address;
PRINT_POINTER(scalloc(85,119););
printStats();
void* p117 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
PRINT_POINTER(smalloc(42););
printStats();
void* p118 = last_address;
PRINT_POINTER(smalloc(105););
printStats();
void* p119 = last_address;
DEBUG_PRINT(sfree(p98););
printStats();
DEBUG_PRINT(sfree(p118););
printStats();
PRINT_POINTER(smalloc(104););
printStats();
void* p120 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p121 = last_address;
PRINT_POINTER(smalloc(158););
printStats();
void* p122 = last_address;
PRINT_POINTER(smalloc(233););
printStats();
void* p123 = last_address;
DEBUG_PRINT(sfree(p74););
printStats();
PRINT_POINTER(srealloc(p117,215););
printStats();
void* p124 = last_address;
DEBUG_PRINT(sfree(p50););
printStats();
DEBUG_PRINT(sfree(p44););
printStats();
PRINT_POINTER(srealloc(p102,156););
printStats();
void* p125 = last_address;
PRINT_POINTER(smalloc(60););
printStats();
void* p126 = last_address;
DEBUG_PRINT(sfree(p107););
printStats();
DEBUG_PRINT(sfree(p99););
printStats();
PRINT_POINTER(smalloc(46););
printStats();
void* p127 = last_address;
PRINT_POINTER(srealloc(p52,246););
printStats();
void* p128 = last_address;
PRINT_POINTER(smalloc(177););
printStats();
void* p129 = last_address;
PRINT_POINTER(scalloc(249,202););
printStats();
void* p130 = last_address;
PRINT_POINTER(srealloc(p112,70););
printStats();
void* p131 = last_address;
PRINT_POINTER(smalloc(233););
printStats();
void* p132 = last_address;
PRINT_POINTER(smalloc(131););
printStats();
void* p133 = last_address;
PRINT_POINTER(smalloc(226););
printStats();
void* p134 = last_address;
DEBUG_PRINT(sfree(p122););
printStats();
PRINT_POINTER(scalloc(15,68););
printStats();
void* p135 = last_address;
PRINT_POINTER(scalloc(65,6););
printStats();
void* p136 = last_address;
PRINT_POINTER(scalloc(194,222););
printStats();
void* p137 = last_address;
PRINT_POINTER(srealloc(p111,54););
printStats();
void* p138 = last_address;
DEBUG_PRINT(sfree(p119););
printStats();
PRINT_POINTER(smalloc(55););
printStats();
void* p139 = last_address;
DEBUG_PRINT(sfree(p87););
printStats();
PRINT_POINTER(srealloc(p75,124););
printStats();
void* p140 = last_address;
DEBUG_PRINT(sfree(p95););
printStats();
PRINT_POINTER(scalloc(116,111););
printStats();
void* p141 = last_address;
PRINT_POINTER(scalloc(173,3););
printStats();
void* p142 = last_address;
PRINT_POINTER(srealloc(p130,167););
printStats();
void* p143 = last_address;
DEBUG_PRINT(sfree(p132););
printStats();
DEBUG_PRINT(sfree(p61););
printStats();
PRINT_POINTER(scalloc(188,181););
printStats();
void* p144 = last_address;
PRINT_POINTER(smalloc(108););
printStats();
void* p145 = last_address;
PRINT_POINTER(srealloc(p66,55););
printStats();
void* p146 = last_address;
PRINT_POINTER(smalloc(98););
printStats();
void* p147 = last_address;
PRINT_POINTER(srealloc(p123,227););
printStats();
void* p148 = last_address;
DEBUG_PRINT(sfree(p137););
printStats();
DEBUG_PRINT(sfree(p109););
printStats();
PRINT_POINTER(srealloc(p91,116););
printStats();
void* p149 = last_address;
DEBUG_PRINT(sfree(p145););
printStats();
DEBUG_PRINT(sfree(p140););
printStats();
PRINT_POINTER(srealloc(p126,191););
printStats();
void* p150 = last_address;
PRINT_POINTER(smalloc(216););
printStats();
void* p151 = last_address;
DEBUG_PRINT(sfree(p105););
printStats();
PRINT_POINTER(smalloc(207););
printStats();
void* p152 = last_address;
DEBUG_PRINT(sfree(p142););
printStats();
PRINT_POINTER(smalloc(132););
printStats();
void* p153 = last_address;
PRINT_POINTER(srealloc(p138,227););
printStats();
void* p154 = last_address;
PRINT_POINTER(srealloc(p57,92););
printStats();
void* p155 = last_address;
PRINT_POINTER(smalloc(229););
printStats();
void* p156 = last_address;
DEBUG_PRINT(sfree(p147););
printStats();
PRINT_POINTER(smalloc(240););
printStats();
void* p157 = last_address;
DEBUG_PRINT(sfree(p110););
printStats();
PRINT_POINTER(smalloc(130););
printStats();
void* p158 = last_address;
PRINT_POINTER(scalloc(87,136););
printStats();
void* p159 = last_address;
DEBUG_PRINT(sfree(p155););
printStats();
PRINT_POINTER(scalloc(213,205););
printStats();
void* p160 = last_address;
DEBUG_PRINT(sfree(p115););
printStats();
PRINT_POINTER(smalloc(25););
printStats();
void* p161 = last_address;
PRINT_POINTER(srealloc(p144,1););
printStats();
void* p162 = last_address;
PRINT_POINTER(smalloc(183););
printStats();
void* p163 = last_address;
PRINT_POINTER(scalloc(208,1););
printStats();
void* p164 = last_address;
PRINT_POINTER(scalloc(195,173););
printStats();
void* p165 = last_address;
PRINT_POINTER(srealloc(p156,224););
printStats();
void* p166 = last_address;
DEBUG_PRINT(sfree(p154););
printStats();
PRINT_POINTER(srealloc(p103,245););
printStats();
void* p167 = last_address;
PRINT_POINTER(srealloc(p78,121););
printStats();
void* p168 = last_address;
PRINT_POINTER(srealloc(p139,58););
printStats();
void* p169 = last_address;
PRINT_POINTER(smalloc(155););
printStats();
void* p170 = last_address;
PRINT_POINTER(smalloc(217););
printStats();
void* p171 = last_address;
PRINT_POINTER(smalloc(187););
printStats();
void* p172 = last_address;
PRINT_POINTER(srealloc(p108,242););
printStats();
void* p173 = last_address;
PRINT_POINTER(scalloc(32,195););
printStats();
void* p174 = last_address;
DEBUG_PRINT(sfree(p114););
printStats();
PRINT_POINTER(srealloc(p136,46););
printStats();
void* p175 = last_address;
PRINT_POINTER(smalloc(130););
printStats();
void* p176 = last_address;
PRINT_POINTER(srealloc(p37,17););
printStats();
void* p177 = last_address;
PRINT_POINTER(smalloc(127););
printStats();
void* p178 = last_address;
PRINT_POINTER(smalloc(29););
printStats();
void* p179 = last_address;
PRINT_POINTER(srealloc(p133,147););
printStats();
void* p180 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p181 = last_address;
PRINT_POINTER(smalloc(112););
printStats();
void* p182 = last_address;
DEBUG_PRINT(sfree(p159););
printStats();
PRINT_POINTER(srealloc(p163,34););
printStats();
void* p183 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p184 = last_address;
DEBUG_PRINT(sfree(p128););
printStats();
DEBUG_PRINT(sfree(p151););
printStats();
PRINT_POINTER(srealloc(p30,205););
printStats();
void* p185 = last_address;
DEBUG_PRINT(sfree(p146););
printStats();
PRINT_POINTER(smalloc(227););
printStats();
void* p186 = last_address;
PRINT_POINTER(scalloc(1,224););
printStats();
void* p187 = last_address;
PRINT_POINTER(smalloc(18););
printStats();
void* p188 = last_address;
PRINT_POINTER(srealloc(p170,201););
printStats();
void* p189 = last_address;
DEBUG_PRINT(sfree(p58););
printStats();
PRINT_POINTER(scalloc(158,241););
printStats();
void* p190 = last_address;
PRINT_POINTER(scalloc(238,82););
printStats();
void* p191 = last_address;
DEBUG_PRINT(sfree(p171););
printStats();
DEBUG_PRINT(sfree(p182););
printStats();
PRINT_POINTER(smalloc(246););
printStats();
void* p192 = last_address;
PRINT_POINTER(scalloc(169,180););
printStats();
void* p193 = last_address;
PRINT_POINTER(smalloc(128););
printStats();
void* p194 = last_address;
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(scalloc(185,241););
printStats();
void* p195 = last_address;
PRINT_POINTER(srealloc(p104,189););
printStats();
void* p196 = last_address;
PRINT_POINTER(smalloc(138););
printStats();
void* p197 = last_address;
PRINT_POINTER(srealloc(p165,20););
printStats();
void* p198 = last_address;
DEBUG_PRINT(sfree(p149););
printStats();
PRINT_POINTER(scalloc(1,158););
printStats();
void* p199 = last_address;
PRINT_POINTER(srealloc(p192,32););
printStats();
void* p200 = last_address;
PRINT_POINTER(srealloc(p179,218););
printStats();
void* p201 = last_address;
PRINT_POINTER(scalloc(131,64););
printStats();
void* p202 = last_address;
DEBUG_PRINT(sfree(p141););
printStats();
PRINT_POINTER(srealloc(p129,123););
printStats();
void* p203 = last_address;
DEBUG_PRINT(sfree(p106););
printStats();
DEBUG_PRINT(sfree(p188););
printStats();
PRINT_POINTER(srealloc(p148,94););
printStats();
void* p204 = last_address;
PRINT_POINTER(smalloc(217););
printStats();
void* p205 = last_address;
PRINT_POINTER(srealloc(p193,194););
printStats();
void* p206 = last_address;
PRINT_POINTER(smalloc(31););
printStats();
void* p207 = last_address;
DEBUG_PRINT(sfree(p199););
printStats();
PRINT_POINTER(srealloc(p189,120););
printStats();
void* p208 = last_address;
PRINT_POINTER(smalloc(14););
printStats();
void* p209 = last_address;
PRINT_POINTER(scalloc(95,14););
printStats();
void* p210 = last_address;
PRINT_POINTER(scalloc(105,99););
printStats();
void* p211 = last_address;
PRINT_POINTER(scalloc(62,57););
printStats();
void* p212 = last_address;
PRINT_POINTER(scalloc(163,83););
printStats();
void* p213 = last_address;
PRINT_POINTER(smalloc(170););
printStats();
void* p214 = last_address;
DEBUG_PRINT(sfree(p116););
printStats();
PRINT_POINTER(srealloc(p183,180););
printStats();
void* p215 = last_address;
PRINT_POINTER(scalloc(134,0););
printStats();
void* p216 = last_address;
PRINT_POINTER(srealloc(p215,226););
printStats();
void* p217 = last_address;
PRINT_POINTER(srealloc(p143,182););
printStats();
void* p218 = last_address;
PRINT_POINTER(scalloc(37,139););
printStats();
void* p219 = last_address;
PRINT_POINTER(smalloc(43););
printStats();
void* p220 = last_address;
PRINT_POINTER(scalloc(117,177););
printStats();
void* p221 = last_address;
DEBUG_PRINT(sfree(p168););
printStats();
PRINT_POINTER(scalloc(221,235););
printStats();
void* p222 = last_address;
DEBUG_PRINT(sfree(p196););
printStats();
PRINT_POINTER(smalloc(31););
printStats();
void* p223 = last_address;
PRINT_POINTER(scalloc(248,111););
printStats();
void* p224 = last_address;
DEBUG_PRINT(sfree(p207););
printStats();
PRINT_POINTER(smalloc(37););
printStats();
void* p225 = last_address;
DEBUG_PRINT(sfree(p210););
printStats();
PRINT_POINTER(srealloc(p167,214););
printStats();
void* p226 = last_address;
PRINT_POINTER(smalloc(116););
printStats();
void* p227 = last_address;
DEBUG_PRINT(sfree(p134););
printStats();
PRINT_POINTER(srealloc(p217,19););
printStats();
void* p228 = last_address;
DEBUG_PRINT(sfree(p198););
printStats();
PRINT_POINTER(smalloc(198););
printStats();
void* p229 = last_address;
PRINT_POINTER(smalloc(70););
printStats();
void* p230 = last_address;
PRINT_POINTER(scalloc(49,82););
printStats();
void* p231 = last_address;
DEBUG_PRINT(sfree(p164););
printStats();
PRINT_POINTER(srealloc(p173,97););
printStats();
void* p232 = last_address;
DEBUG_PRINT(sfree(p184););
printStats();
PRINT_POINTER(srealloc(p216,230););
printStats();
void* p233 = last_address;
PRINT_POINTER(srealloc(p81,101););
printStats();
void* p234 = last_address;
PRINT_POINTER(scalloc(95,229););
printStats();
void* p235 = last_address;
PRINT_POINTER(smalloc(212););
printStats();
void* p236 = last_address;
PRINT_POINTER(srealloc(p230,120););
printStats();
void* p237 = last_address;
PRINT_POINTER(srealloc(p158,6););
printStats();
void* p238 = last_address;
PRINT_POINTER(srealloc(p157,126););
printStats();
void* p239 = last_address;
PRINT_POINTER(scalloc(49,58););
printStats();
void* p240 = last_address;
PRINT_POINTER(srealloc(p195,233););
printStats();
void* p241 = last_address;
DEBUG_PRINT(sfree(p236););
printStats();
PRINT_POINTER(scalloc(214,1););
printStats();
void* p242 = last_address;
PRINT_POINTER(scalloc(60,1););
printStats();
void* p243 = last_address;
PRINT_POINTER(smalloc(102););
printStats();
void* p244 = last_address;
DEBUG_PRINT(sfree(p160););
printStats();
PRINT_POINTER(smalloc(126););
printStats();
void* p245 = last_address;
PRINT_POINTER(scalloc(194,218););
printStats();
void* p246 = last_address;
PRINT_POINTER(smalloc(107););
printStats();
void* p247 = last_address;
PRINT_POINTER(srealloc(p175,211););
printStats();
void* p248 = last_address;
PRINT_POINTER(smalloc(20););
printStats();
void* p249 = last_address;
PRINT_POINTER(srealloc(p233,41););
printStats();
void* p250 = last_address;
}