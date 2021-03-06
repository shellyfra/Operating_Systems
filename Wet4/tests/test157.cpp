#include "aux_macro.h"
#include "../malloc_2.cpp"
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
                        PRINT_POINTER(scalloc(21,181););
printStats();
void* p0 = last_address;
DEBUG_PRINT(sfree(p0););
printStats();
PRINT_POINTER(scalloc(248,236););
printStats();
void* p1 = last_address;
DEBUG_PRINT(sfree(p1););
printStats();
PRINT_POINTER(scalloc(49,228););
printStats();
void* p2 = last_address;
PRINT_POINTER(srealloc(p2,120););
printStats();
void* p3 = last_address;
PRINT_POINTER(scalloc(177,180););
printStats();
void* p4 = last_address;
PRINT_POINTER(scalloc(231,230););
printStats();
void* p5 = last_address;
PRINT_POINTER(smalloc(153););
printStats();
void* p6 = last_address;
PRINT_POINTER(srealloc(p5,116););
printStats();
void* p7 = last_address;
PRINT_POINTER(srealloc(p3,160););
printStats();
void* p8 = last_address;
DEBUG_PRINT(sfree(p8););
printStats();
PRINT_POINTER(srealloc(p6,187););
printStats();
void* p9 = last_address;
DEBUG_PRINT(sfree(p7););
printStats();
PRINT_POINTER(srealloc(p9,62););
printStats();
void* p10 = last_address;
PRINT_POINTER(srealloc(p10,218););
printStats();
void* p11 = last_address;
DEBUG_PRINT(sfree(p4););
printStats();
PRINT_POINTER(smalloc(166););
printStats();
void* p12 = last_address;
PRINT_POINTER(srealloc(p12,7););
printStats();
void* p13 = last_address;
PRINT_POINTER(srealloc(p11,55););
printStats();
void* p14 = last_address;
PRINT_POINTER(smalloc(55););
printStats();
void* p15 = last_address;
PRINT_POINTER(srealloc(p15,27););
printStats();
void* p16 = last_address;
PRINT_POINTER(scalloc(164,17););
printStats();
void* p17 = last_address;
PRINT_POINTER(scalloc(192,86););
printStats();
void* p18 = last_address;
PRINT_POINTER(scalloc(185,112););
printStats();
void* p19 = last_address;
PRINT_POINTER(srealloc(p18,96););
printStats();
void* p20 = last_address;
DEBUG_PRINT(sfree(p20););
printStats();
DEBUG_PRINT(sfree(p16););
printStats();
DEBUG_PRINT(sfree(p13););
printStats();
PRINT_POINTER(smalloc(86););
printStats();
void* p21 = last_address;
PRINT_POINTER(srealloc(p17,227););
printStats();
void* p22 = last_address;
DEBUG_PRINT(sfree(p21););
printStats();
PRINT_POINTER(smalloc(9););
printStats();
void* p23 = last_address;
DEBUG_PRINT(sfree(p22););
printStats();
PRINT_POINTER(srealloc(p14,30););
printStats();
void* p24 = last_address;
DEBUG_PRINT(sfree(p23););
printStats();
PRINT_POINTER(smalloc(56););
printStats();
void* p25 = last_address;
PRINT_POINTER(smalloc(25););
printStats();
void* p26 = last_address;
PRINT_POINTER(smalloc(131););
printStats();
void* p27 = last_address;
PRINT_POINTER(srealloc(p24,153););
printStats();
void* p28 = last_address;
PRINT_POINTER(smalloc(219););
printStats();
void* p29 = last_address;
PRINT_POINTER(srealloc(p19,168););
printStats();
void* p30 = last_address;
PRINT_POINTER(smalloc(186););
printStats();
void* p31 = last_address;
PRINT_POINTER(smalloc(51););
printStats();
void* p32 = last_address;
PRINT_POINTER(srealloc(p29,150););
printStats();
void* p33 = last_address;
DEBUG_PRINT(sfree(p32););
printStats();
PRINT_POINTER(scalloc(175,157););
printStats();
void* p34 = last_address;
PRINT_POINTER(scalloc(127,13););
printStats();
void* p35 = last_address;
DEBUG_PRINT(sfree(p28););
printStats();
PRINT_POINTER(srealloc(p30,152););
printStats();
void* p36 = last_address;
DEBUG_PRINT(sfree(p33););
printStats();
PRINT_POINTER(scalloc(206,220););
printStats();
void* p37 = last_address;
PRINT_POINTER(srealloc(p36,36););
printStats();
void* p38 = last_address;
DEBUG_PRINT(sfree(p37););
printStats();
DEBUG_PRINT(sfree(p26););
printStats();
PRINT_POINTER(smalloc(90););
printStats();
void* p39 = last_address;
PRINT_POINTER(srealloc(p39,128););
printStats();
void* p40 = last_address;
DEBUG_PRINT(sfree(p34););
printStats();
PRINT_POINTER(scalloc(194,49););
printStats();
void* p41 = last_address;
PRINT_POINTER(scalloc(226,100););
printStats();
void* p42 = last_address;
PRINT_POINTER(srealloc(p27,0););
printStats();
void* p43 = last_address;
PRINT_POINTER(scalloc(207,201););
printStats();
void* p44 = last_address;
PRINT_POINTER(smalloc(24););
printStats();
void* p45 = last_address;
PRINT_POINTER(scalloc(218,147););
printStats();
void* p46 = last_address;
PRINT_POINTER(scalloc(81,80););
printStats();
void* p47 = last_address;
PRINT_POINTER(smalloc(168););
printStats();
void* p48 = last_address;
PRINT_POINTER(scalloc(13,247););
printStats();
void* p49 = last_address;
PRINT_POINTER(scalloc(128,132););
printStats();
void* p50 = last_address;
DEBUG_PRINT(sfree(p48););
printStats();
PRINT_POINTER(smalloc(66););
printStats();
void* p51 = last_address;
PRINT_POINTER(scalloc(32,235););
printStats();
void* p52 = last_address;
DEBUG_PRINT(sfree(p45););
printStats();
PRINT_POINTER(smalloc(98););
printStats();
void* p53 = last_address;
PRINT_POINTER(scalloc(93,75););
printStats();
void* p54 = last_address;
DEBUG_PRINT(sfree(p52););
printStats();
PRINT_POINTER(smalloc(238););
printStats();
void* p55 = last_address;
PRINT_POINTER(srealloc(p31,167););
printStats();
void* p56 = last_address;
PRINT_POINTER(scalloc(20,124););
printStats();
void* p57 = last_address;
PRINT_POINTER(smalloc(161););
printStats();
void* p58 = last_address;
PRINT_POINTER(scalloc(198,80););
printStats();
void* p59 = last_address;
PRINT_POINTER(smalloc(121););
printStats();
void* p60 = last_address;
PRINT_POINTER(srealloc(p58,244););
printStats();
void* p61 = last_address;
PRINT_POINTER(scalloc(41,49););
printStats();
void* p62 = last_address;
PRINT_POINTER(srealloc(p47,20););
printStats();
void* p63 = last_address;
PRINT_POINTER(smalloc(148););
printStats();
void* p64 = last_address;
PRINT_POINTER(scalloc(115,13););
printStats();
void* p65 = last_address;
DEBUG_PRINT(sfree(p64););
printStats();
DEBUG_PRINT(sfree(p61););
printStats();
PRINT_POINTER(srealloc(p25,9););
printStats();
void* p66 = last_address;
PRINT_POINTER(srealloc(p50,214););
printStats();
void* p67 = last_address;
PRINT_POINTER(scalloc(188,153););
printStats();
void* p68 = last_address;
PRINT_POINTER(smalloc(180););
printStats();
void* p69 = last_address;
PRINT_POINTER(srealloc(p41,128););
printStats();
void* p70 = last_address;
PRINT_POINTER(scalloc(160,208););
printStats();
void* p71 = last_address;
PRINT_POINTER(srealloc(p53,8););
printStats();
void* p72 = last_address;
PRINT_POINTER(srealloc(p62,119););
printStats();
void* p73 = last_address;
PRINT_POINTER(srealloc(p63,233););
printStats();
void* p74 = last_address;
PRINT_POINTER(smalloc(53););
printStats();
void* p75 = last_address;
PRINT_POINTER(srealloc(p56,70););
printStats();
void* p76 = last_address;
PRINT_POINTER(srealloc(p69,236););
printStats();
void* p77 = last_address;
PRINT_POINTER(srealloc(p42,111););
printStats();
void* p78 = last_address;
DEBUG_PRINT(sfree(p60););
printStats();
PRINT_POINTER(smalloc(201););
printStats();
void* p79 = last_address;
PRINT_POINTER(scalloc(145,121););
printStats();
void* p80 = last_address;
PRINT_POINTER(srealloc(p59,1););
printStats();
void* p81 = last_address;
PRINT_POINTER(smalloc(202););
printStats();
void* p82 = last_address;
DEBUG_PRINT(sfree(p49););
printStats();
PRINT_POINTER(scalloc(139,180););
printStats();
void* p83 = last_address;
PRINT_POINTER(smalloc(245););
printStats();
void* p84 = last_address;
PRINT_POINTER(srealloc(p71,0););
printStats();
void* p85 = last_address;
PRINT_POINTER(scalloc(195,61););
printStats();
void* p86 = last_address;
PRINT_POINTER(smalloc(42););
printStats();
void* p87 = last_address;
DEBUG_PRINT(sfree(p35););
printStats();
DEBUG_PRINT(sfree(p54););
printStats();
DEBUG_PRINT(sfree(p66););
printStats();
PRINT_POINTER(smalloc(227););
printStats();
void* p88 = last_address;
PRINT_POINTER(smalloc(67););
printStats();
void* p89 = last_address;
PRINT_POINTER(smalloc(62););
printStats();
void* p90 = last_address;
PRINT_POINTER(smalloc(248););
printStats();
void* p91 = last_address;
DEBUG_PRINT(sfree(p55););
printStats();
DEBUG_PRINT(sfree(p91););
printStats();
PRINT_POINTER(scalloc(200,56););
printStats();
void* p92 = last_address;
DEBUG_PRINT(sfree(p46););
printStats();
DEBUG_PRINT(sfree(p84););
printStats();
PRINT_POINTER(srealloc(p79,231););
printStats();
void* p93 = last_address;
DEBUG_PRINT(sfree(p93););
printStats();
PRINT_POINTER(scalloc(140,69););
printStats();
void* p94 = last_address;
PRINT_POINTER(scalloc(171,172););
printStats();
void* p95 = last_address;
PRINT_POINTER(scalloc(201,67););
printStats();
void* p96 = last_address;
PRINT_POINTER(scalloc(155,76););
printStats();
void* p97 = last_address;
PRINT_POINTER(scalloc(72,123););
printStats();
void* p98 = last_address;
DEBUG_PRINT(sfree(p96););
printStats();
PRINT_POINTER(srealloc(p87,198););
printStats();
void* p99 = last_address;
PRINT_POINTER(srealloc(p90,210););
printStats();
void* p100 = last_address;
PRINT_POINTER(scalloc(236,222););
printStats();
void* p101 = last_address;
DEBUG_PRINT(sfree(p99););
printStats();
PRINT_POINTER(scalloc(24,182););
printStats();
void* p102 = last_address;
PRINT_POINTER(scalloc(246,24););
printStats();
void* p103 = last_address;
DEBUG_PRINT(sfree(p86););
printStats();
DEBUG_PRINT(sfree(p85););
printStats();
PRINT_POINTER(scalloc(28,177););
printStats();
void* p104 = last_address;
PRINT_POINTER(smalloc(181););
printStats();
void* p105 = last_address;
DEBUG_PRINT(sfree(p65););
printStats();
DEBUG_PRINT(sfree(p83););
printStats();
DEBUG_PRINT(sfree(p80););
printStats();
DEBUG_PRINT(sfree(p98););
printStats();
PRINT_POINTER(smalloc(50););
printStats();
void* p106 = last_address;
PRINT_POINTER(smalloc(100););
printStats();
void* p107 = last_address;
PRINT_POINTER(srealloc(p97,236););
printStats();
void* p108 = last_address;
PRINT_POINTER(scalloc(199,199););
printStats();
void* p109 = last_address;
PRINT_POINTER(srealloc(p75,42););
printStats();
void* p110 = last_address;
DEBUG_PRINT(sfree(p74););
printStats();
PRINT_POINTER(scalloc(51,90););
printStats();
void* p111 = last_address;
DEBUG_PRINT(sfree(p110););
printStats();
PRINT_POINTER(scalloc(57,152););
printStats();
void* p112 = last_address;
PRINT_POINTER(smalloc(112););
printStats();
void* p113 = last_address;
PRINT_POINTER(smalloc(229););
printStats();
void* p114 = last_address;
PRINT_POINTER(smalloc(6););
printStats();
void* p115 = last_address;
PRINT_POINTER(scalloc(10,107););
printStats();
void* p116 = last_address;
PRINT_POINTER(srealloc(p76,167););
printStats();
void* p117 = last_address;
PRINT_POINTER(smalloc(214););
printStats();
void* p118 = last_address;
PRINT_POINTER(srealloc(p82,236););
printStats();
void* p119 = last_address;
PRINT_POINTER(smalloc(44););
printStats();
void* p120 = last_address;
PRINT_POINTER(srealloc(p78,37););
printStats();
void* p121 = last_address;
PRINT_POINTER(srealloc(p103,42););
printStats();
void* p122 = last_address;
DEBUG_PRINT(sfree(p106););
printStats();
PRINT_POINTER(scalloc(121,168););
printStats();
void* p123 = last_address;
DEBUG_PRINT(sfree(p101););
printStats();
DEBUG_PRINT(sfree(p107););
printStats();
PRINT_POINTER(smalloc(238););
printStats();
void* p124 = last_address;
PRINT_POINTER(scalloc(200,199););
printStats();
void* p125 = last_address;
PRINT_POINTER(scalloc(128,189););
printStats();
void* p126 = last_address;
PRINT_POINTER(smalloc(191););
printStats();
void* p127 = last_address;
DEBUG_PRINT(sfree(p44););
printStats();
PRINT_POINTER(scalloc(115,128););
printStats();
void* p128 = last_address;
DEBUG_PRINT(sfree(p124););
printStats();
DEBUG_PRINT(sfree(p57););
printStats();
PRINT_POINTER(srealloc(p88,234););
printStats();
void* p129 = last_address;
PRINT_POINTER(srealloc(p108,187););
printStats();
void* p130 = last_address;
PRINT_POINTER(scalloc(107,221););
printStats();
void* p131 = last_address;
PRINT_POINTER(srealloc(p121,183););
printStats();
void* p132 = last_address;
DEBUG_PRINT(sfree(p126););
printStats();
PRINT_POINTER(scalloc(203,184););
printStats();
void* p133 = last_address;
DEBUG_PRINT(sfree(p68););
printStats();
PRINT_POINTER(smalloc(185););
printStats();
void* p134 = last_address;
DEBUG_PRINT(sfree(p114););
printStats();
PRINT_POINTER(smalloc(245););
printStats();
void* p135 = last_address;
PRINT_POINTER(srealloc(p51,137););
printStats();
void* p136 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p137 = last_address;
PRINT_POINTER(scalloc(197,232););
printStats();
void* p138 = last_address;
PRINT_POINTER(scalloc(26,74););
printStats();
void* p139 = last_address;
PRINT_POINTER(smalloc(63););
printStats();
void* p140 = last_address;
DEBUG_PRINT(sfree(p43););
printStats();
PRINT_POINTER(scalloc(1,157););
printStats();
void* p141 = last_address;
PRINT_POINTER(smalloc(93););
printStats();
void* p142 = last_address;
PRINT_POINTER(smalloc(16););
printStats();
void* p143 = last_address;
PRINT_POINTER(smalloc(201););
printStats();
void* p144 = last_address;
PRINT_POINTER(srealloc(p134,29););
printStats();
void* p145 = last_address;
PRINT_POINTER(srealloc(p131,90););
printStats();
void* p146 = last_address;
PRINT_POINTER(srealloc(p133,229););
printStats();
void* p147 = last_address;
PRINT_POINTER(srealloc(p139,165););
printStats();
void* p148 = last_address;
DEBUG_PRINT(sfree(p102););
printStats();
DEBUG_PRINT(sfree(p70););
printStats();
DEBUG_PRINT(sfree(p140););
printStats();
PRINT_POINTER(scalloc(183,44););
printStats();
void* p149 = last_address;
PRINT_POINTER(srealloc(p118,221););
printStats();
void* p150 = last_address;
PRINT_POINTER(smalloc(187););
printStats();
void* p151 = last_address;
PRINT_POINTER(srealloc(p112,88););
printStats();
void* p152 = last_address;
PRINT_POINTER(srealloc(p150,155););
printStats();
void* p153 = last_address;
DEBUG_PRINT(sfree(p141););
printStats();
PRINT_POINTER(scalloc(27,93););
printStats();
void* p154 = last_address;
PRINT_POINTER(smalloc(53););
printStats();
void* p155 = last_address;
PRINT_POINTER(smalloc(93););
printStats();
void* p156 = last_address;
PRINT_POINTER(srealloc(p92,134););
printStats();
void* p157 = last_address;
PRINT_POINTER(smalloc(98););
printStats();
void* p158 = last_address;
PRINT_POINTER(srealloc(p143,158););
printStats();
void* p159 = last_address;
PRINT_POINTER(smalloc(100););
printStats();
void* p160 = last_address;
PRINT_POINTER(smalloc(167););
printStats();
void* p161 = last_address;
PRINT_POINTER(srealloc(p138,234););
printStats();
void* p162 = last_address;
PRINT_POINTER(scalloc(57,161););
printStats();
void* p163 = last_address;
DEBUG_PRINT(sfree(p142););
printStats();
PRINT_POINTER(scalloc(96,68););
printStats();
void* p164 = last_address;
DEBUG_PRINT(sfree(p100););
printStats();
DEBUG_PRINT(sfree(p40););
printStats();
DEBUG_PRINT(sfree(p159););
printStats();
PRINT_POINTER(srealloc(p160,148););
printStats();
void* p165 = last_address;
PRINT_POINTER(scalloc(89,154););
printStats();
void* p166 = last_address;
PRINT_POINTER(srealloc(p164,179););
printStats();
void* p167 = last_address;
PRINT_POINTER(srealloc(p72,5););
printStats();
void* p168 = last_address;
PRINT_POINTER(srealloc(p111,60););
printStats();
void* p169 = last_address;
PRINT_POINTER(srealloc(p167,85););
printStats();
void* p170 = last_address;
PRINT_POINTER(smalloc(137););
printStats();
void* p171 = last_address;
DEBUG_PRINT(sfree(p95););
printStats();
PRINT_POINTER(scalloc(62,103););
printStats();
void* p172 = last_address;
PRINT_POINTER(smalloc(42););
printStats();
void* p173 = last_address;
DEBUG_PRINT(sfree(p158););
printStats();
DEBUG_PRINT(sfree(p146););
printStats();
PRINT_POINTER(srealloc(p169,186););
printStats();
void* p174 = last_address;
PRINT_POINTER(scalloc(121,158););
printStats();
void* p175 = last_address;
PRINT_POINTER(scalloc(36,2););
printStats();
void* p176 = last_address;
PRINT_POINTER(scalloc(87,128););
printStats();
void* p177 = last_address;
DEBUG_PRINT(sfree(p173););
printStats();
PRINT_POINTER(srealloc(p152,41););
printStats();
void* p178 = last_address;
PRINT_POINTER(smalloc(8););
printStats();
void* p179 = last_address;
PRINT_POINTER(smalloc(118););
printStats();
void* p180 = last_address;
DEBUG_PRINT(sfree(p117););
printStats();
PRINT_POINTER(smalloc(137););
printStats();
void* p181 = last_address;
PRINT_POINTER(srealloc(p127,234););
printStats();
void* p182 = last_address;
PRINT_POINTER(scalloc(112,152););
printStats();
void* p183 = last_address;
PRINT_POINTER(smalloc(186););
printStats();
void* p184 = last_address;
PRINT_POINTER(smalloc(94););
printStats();
void* p185 = last_address;
PRINT_POINTER(smalloc(246););
printStats();
void* p186 = last_address;
DEBUG_PRINT(sfree(p171););
printStats();
PRINT_POINTER(smalloc(158););
printStats();
void* p187 = last_address;
PRINT_POINTER(smalloc(24););
printStats();
void* p188 = last_address;
PRINT_POINTER(smalloc(117););
printStats();
void* p189 = last_address;
PRINT_POINTER(srealloc(p147,84););
printStats();
void* p190 = last_address;
DEBUG_PRINT(sfree(p135););
printStats();
PRINT_POINTER(smalloc(220););
printStats();
void* p191 = last_address;
PRINT_POINTER(srealloc(p175,26););
printStats();
void* p192 = last_address;
DEBUG_PRINT(sfree(p168););
printStats();
PRINT_POINTER(srealloc(p186,244););
printStats();
void* p193 = last_address;
PRINT_POINTER(scalloc(94,198););
printStats();
void* p194 = last_address;
PRINT_POINTER(srealloc(p182,45););
printStats();
void* p195 = last_address;
DEBUG_PRINT(sfree(p184););
printStats();
PRINT_POINTER(srealloc(p153,163););
printStats();
void* p196 = last_address;
PRINT_POINTER(scalloc(68,234););
printStats();
void* p197 = last_address;
PRINT_POINTER(srealloc(p123,205););
printStats();
void* p198 = last_address;
PRINT_POINTER(smalloc(149););
printStats();
void* p199 = last_address;
DEBUG_PRINT(sfree(p73););
printStats();
PRINT_POINTER(smalloc(32););
printStats();
void* p200 = last_address;
DEBUG_PRINT(sfree(p151););
printStats();
PRINT_POINTER(srealloc(p149,3););
printStats();
void* p201 = last_address;
PRINT_POINTER(smalloc(157););
printStats();
void* p202 = last_address;
PRINT_POINTER(scalloc(77,220););
printStats();
void* p203 = last_address;
DEBUG_PRINT(sfree(p191););
printStats();
PRINT_POINTER(scalloc(100,134););
printStats();
void* p204 = last_address;
PRINT_POINTER(scalloc(72,216););
printStats();
void* p205 = last_address;
PRINT_POINTER(srealloc(p193,79););
printStats();
void* p206 = last_address;
PRINT_POINTER(srealloc(p178,151););
printStats();
void* p207 = last_address;
DEBUG_PRINT(sfree(p105););
printStats();
DEBUG_PRINT(sfree(p203););
printStats();
PRINT_POINTER(srealloc(p89,244););
printStats();
void* p208 = last_address;
DEBUG_PRINT(sfree(p132););
printStats();
PRINT_POINTER(scalloc(202,30););
printStats();
void* p209 = last_address;
PRINT_POINTER(smalloc(189););
printStats();
void* p210 = last_address;
DEBUG_PRINT(sfree(p197););
printStats();
DEBUG_PRINT(sfree(p67););
printStats();
PRINT_POINTER(scalloc(125,124););
printStats();
void* p211 = last_address;
PRINT_POINTER(smalloc(88););
printStats();
void* p212 = last_address;
DEBUG_PRINT(sfree(p137););
printStats();
DEBUG_PRINT(sfree(p145););
printStats();
PRINT_POINTER(smalloc(101););
printStats();
void* p213 = last_address;
PRINT_POINTER(smalloc(203););
printStats();
void* p214 = last_address;
PRINT_POINTER(scalloc(205,31););
printStats();
void* p215 = last_address;
PRINT_POINTER(srealloc(p209,47););
printStats();
void* p216 = last_address;
PRINT_POINTER(srealloc(p212,58););
printStats();
void* p217 = last_address;
DEBUG_PRINT(sfree(p206););
printStats();
PRINT_POINTER(srealloc(p38,147););
printStats();
void* p218 = last_address;
PRINT_POINTER(scalloc(63,132););
printStats();
void* p219 = last_address;
PRINT_POINTER(smalloc(208););
printStats();
void* p220 = last_address;
DEBUG_PRINT(sfree(p154););
printStats();
PRINT_POINTER(scalloc(29,27););
printStats();
void* p221 = last_address;
PRINT_POINTER(srealloc(p204,238););
printStats();
void* p222 = last_address;
PRINT_POINTER(srealloc(p201,191););
printStats();
void* p223 = last_address;
DEBUG_PRINT(sfree(p181););
printStats();
PRINT_POINTER(smalloc(109););
printStats();
void* p224 = last_address;
PRINT_POINTER(srealloc(p156,237););
printStats();
void* p225 = last_address;
PRINT_POINTER(smalloc(214););
printStats();
void* p226 = last_address;
PRINT_POINTER(srealloc(p129,25););
printStats();
void* p227 = last_address;
PRINT_POINTER(smalloc(149););
printStats();
void* p228 = last_address;
PRINT_POINTER(srealloc(p196,87););
printStats();
void* p229 = last_address;
PRINT_POINTER(scalloc(217,133););
printStats();
void* p230 = last_address;
DEBUG_PRINT(sfree(p226););
printStats();
PRINT_POINTER(srealloc(p162,131););
printStats();
void* p231 = last_address;
DEBUG_PRINT(sfree(p210););
printStats();
PRINT_POINTER(smalloc(236););
printStats();
void* p232 = last_address;
PRINT_POINTER(smalloc(58););
printStats();
void* p233 = last_address;
PRINT_POINTER(smalloc(47););
printStats();
void* p234 = last_address;
PRINT_POINTER(scalloc(245,82););
printStats();
void* p235 = last_address;
PRINT_POINTER(scalloc(141,10););
printStats();
void* p236 = last_address;
PRINT_POINTER(smalloc(75););
printStats();
void* p237 = last_address;
PRINT_POINTER(scalloc(63,54););
printStats();
void* p238 = last_address;
PRINT_POINTER(srealloc(p130,66););
printStats();
void* p239 = last_address;
PRINT_POINTER(srealloc(p189,15););
printStats();
void* p240 = last_address;
PRINT_POINTER(scalloc(167,193););
printStats();
void* p241 = last_address;
PRINT_POINTER(smalloc(246););
printStats();
void* p242 = last_address;
DEBUG_PRINT(sfree(p239););
printStats();
DEBUG_PRINT(sfree(p235););
printStats();
PRINT_POINTER(srealloc(p207,234););
printStats();
void* p243 = last_address;
PRINT_POINTER(smalloc(182););
printStats();
void* p244 = last_address;
PRINT_POINTER(scalloc(38,228););
printStats();
void* p245 = last_address;
PRINT_POINTER(srealloc(p214,78););
printStats();
void* p246 = last_address;
PRINT_POINTER(smalloc(195););
printStats();
void* p247 = last_address;
PRINT_POINTER(smalloc(188););
printStats();
void* p248 = last_address;
PRINT_POINTER(smalloc(97););
printStats();
void* p249 = last_address;
PRINT_POINTER(srealloc(p179,157););
printStats();
void* p250 = last_address;
PRINT_POINTER(scalloc(155,46););
printStats();
void* p251 = last_address;
PRINT_POINTER(srealloc(p242,177););
printStats();
void* p252 = last_address;
PRINT_POINTER(srealloc(p166,245););
printStats();
void* p253 = last_address;
PRINT_POINTER(scalloc(248,95););
printStats();
void* p254 = last_address;
PRINT_POINTER(srealloc(p223,96););
printStats();
void* p255 = last_address;
PRINT_POINTER(srealloc(p185,49););
printStats();
void* p256 = last_address;
PRINT_POINTER(srealloc(p244,132););
printStats();
void* p257 = last_address;
PRINT_POINTER(scalloc(156,225););
printStats();
void* p258 = last_address;
PRINT_POINTER(smalloc(224););
printStats();
void* p259 = last_address;
PRINT_POINTER(srealloc(p198,4););
printStats();
void* p260 = last_address;
DEBUG_PRINT(sfree(p222););
printStats();
PRINT_POINTER(scalloc(149,33););
printStats();
void* p261 = last_address;
PRINT_POINTER(srealloc(p94,102););
printStats();
void* p262 = last_address;
PRINT_POINTER(scalloc(77,4););
printStats();
void* p263 = last_address;
DEBUG_PRINT(sfree(p253););
printStats();
DEBUG_PRINT(sfree(p136););
printStats();
PRINT_POINTER(srealloc(p258,122););
printStats();
void* p264 = last_address;
PRINT_POINTER(smalloc(213););
printStats();
void* p265 = last_address;
PRINT_POINTER(smalloc(216););
printStats();
void* p266 = last_address;
PRINT_POINTER(smalloc(39););
printStats();
void* p267 = last_address;
PRINT_POINTER(srealloc(p120,18););
printStats();
void* p268 = last_address;
DEBUG_PRINT(sfree(p180););
printStats();
PRINT_POINTER(scalloc(246,19););
printStats();
void* p269 = last_address;
PRINT_POINTER(smalloc(65););
printStats();
void* p270 = last_address;
PRINT_POINTER(smalloc(221););
printStats();
void* p271 = last_address;
PRINT_POINTER(srealloc(p251,135););
printStats();
void* p272 = last_address;
PRINT_POINTER(smalloc(88););
printStats();
void* p273 = last_address;
PRINT_POINTER(smalloc(245););
printStats();
void* p274 = last_address;
DEBUG_PRINT(sfree(p224););
printStats();
PRINT_POINTER(smalloc(163););
printStats();
void* p275 = last_address;
PRINT_POINTER(scalloc(116,69););
printStats();
void* p276 = last_address;
PRINT_POINTER(smalloc(102););
printStats();
void* p277 = last_address;
PRINT_POINTER(srealloc(p233,195););
printStats();
void* p278 = last_address;
PRINT_POINTER(smalloc(100););
printStats();
void* p279 = last_address;
PRINT_POINTER(smalloc(20););
printStats();
void* p280 = last_address;
PRINT_POINTER(smalloc(123););
printStats();
void* p281 = last_address;
PRINT_POINTER(smalloc(30););
printStats();
void* p282 = last_address;
DEBUG_PRINT(sfree(p199););
printStats();
DEBUG_PRINT(sfree(p250););
printStats();
PRINT_POINTER(srealloc(p275,67););
printStats();
void* p283 = last_address;
DEBUG_PRINT(sfree(p155););
printStats();
DEBUG_PRINT(sfree(p109););
printStats();
PRINT_POINTER(scalloc(31,220););
printStats();
void* p284 = last_address;
}
