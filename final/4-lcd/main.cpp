/*
 * Template of program with configuration of LCD screen with HD4470 driver
 * Pawel Krol - Politechnika Krakowska - 2019/2020
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include "hd44780/hd44780.hpp"
#include <stdbool.h>
#include <stdio.h>

int main (void){

    LCD_Initalize();
    int i;
    bool option;

    DDRD |= (1<< PD7);
    	// LEDS CONTROLLER
    	DDRB |= ((1 << DDB2) | (1 << DDB3) | (1 << DDB4) | (1 << DDB5)); // Direction of port line (1 - output)
    	PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5); // Output register (1 - do not light)
    	// BUTTONS CONTROLLER
    	DDRD &= ~(1<<DDD0) | ~(1<<DDD1) | ~(1<<DDD2) | ~(1<<DDD3); // Direction of port line (0 - input)

    	//LEVEL 1
    	LCD_Clear();
    	LCD_GoTo(2,0);
    	LCD_WriteText("LEVEL 1");
    	_delay_ms(500);
    	PORTB ^= (1<<PORTB4);
    	_delay_ms(500);
    	PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	i = 0;
    	int es1[1];
    	option=false;
    	while(i<2){
			if(i==1){
				if(es1[0]==2){
						option=true;
				}
				if(option==true){
					LCD_Clear();
					LCD_GoTo(1,0);
					LCD_WriteText("COMPLETED LVL1");
					_delay_ms(1000);
					i++;
				}
				else{
					LCD_Clear();
					LCD_GoTo(2,0);
					LCD_WriteText("GAME OVER");
					_delay_ms(500);

				}
			}


			else if (!(PIND & 1<<PIND3)){
				es1[i]=3;
				i++;
				LCD_Clear();
				LCD_GoTo(2,0);
				LCD_WriteText("SELECTED N1");
				_delay_ms(500);
			}
			else if (!(PIND & 1<<PIND2)){
				es1[i]=2;
				i++;
				LCD_Clear();
				LCD_GoTo(2,0);
				LCD_WriteText("SELECTED N2");
				_delay_ms(500);
			}
			else if (!(PIND & 1<<PIND1)){
				es1[i]=1;
				i++;
				LCD_Clear();
				LCD_GoTo(2,0);
				LCD_WriteText("SELECTED N3");
				_delay_ms(500);
			}
			else if (!(PIND & 1<<PIND0)){
				es1[i]=0;
				i++;
				LCD_Clear();
				LCD_GoTo(2,0);
				LCD_WriteText("SELECTED N4");
				_delay_ms(500);
			}

    	}



    	//LEVEL 2
    	    	    	    	    	    	    	LCD_Clear();
    	    	    	    	    	    	    	LCD_GoTo(2,0);
    	    	    	    	    	    	    	LCD_WriteText("LEVEL 2");
    	    	    	    	    	    	    	_delay_ms(500);
    	    	    	    	    	PORTB ^= (1<<PORTB4);
    	    	    	    	    	    	_delay_ms(500);
    	    	    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    	    	    	    	PORTB ^= (1<<PORTB5);
    	    	    	    	    	    	_delay_ms(500);
    	    	    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    	    	    			 i = 0;
    	    	    	    	    			int es2[2];
    	    	    	    	    			 option=false;
    	    	    	    	    			while(i<3){
    	    	    	    	    				if(i==2){
    	    	    	    	    					if(es2[0]==2){
    	    	    	    	    						if(es2[1]==3){
    	    	    	    	    												option=true;
    	    	    	    	    						}
    	    	    	    	    					}
    	    	    	    	    					if(option==true){
    	    	    	    	    						LCD_Clear();
    	    	    	    	    						LCD_GoTo(1,0);
    	    	    	    	    						LCD_WriteText("COMPLETED LVL2");
    	    	    	    	    						_delay_ms(1000);
        	    	    	    	    					i++;
    	    	    	    	    					}
    	    	    	    	    					else{
    	    	    	    	    						LCD_Clear();
    	    	    	    	    						LCD_GoTo(2,0);
    	    	    	    	    						LCD_WriteText("GAME OVER");
    	    	    	    	    						_delay_ms(500);

    	    	    	    	    					}
    	    	    	    	    				}


    	    	    	    	    				else if (!(PIND & 1<<PIND3)){
    	    	    	    	    	    				es2[i]=3;
    	    	    	    	    	    				i++;
    	    	    	    	    	    				LCD_Clear();
    	    	    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    	    	    				            LCD_WriteText("SELECTED N1");
    	    	    	    	    	    				            _delay_ms(500);
    	    	    	    	    	    			}
    	    	    	    	    	    			else if (!(PIND & 1<<PIND2)){
    	    	    	    	    	    				es2[i]=2;
    	    	    	    	    	    				i++;
    	    	    	    	    	    				LCD_Clear();
    	    	    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    	    	    				            LCD_WriteText("SELECTED N2");
    	    	    	    	    	    				            _delay_ms(500);
    	    	    	    	    	    			}
    	    	    	    	    	    			else if (!(PIND & 1<<PIND1)){
    	    	    	    	    	    				es2[i]=1;
    	    	    	    	    	    				i++;
    	    	    	    	    	    				LCD_Clear();
    	    	    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    	    	    				            LCD_WriteText("SELECTED N3");
    	    	    	    	    	    				            _delay_ms(500);
    	    	    	    	    	    			}
    	    	    	    	    	    			else if (!(PIND & 1<<PIND0)){
    	    	    	    	    	    				es2[i]=0;
    	    	    	    	    	    				i++;
    	    	    	    	    	    				LCD_Clear();
    	    	    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    	    	    				            LCD_WriteText("SELECTED N4");
    	    	    	    	    	    				            _delay_ms(500);
    	    	    	    	    	    			}

    	    	    	    	    	    }


    	//LEVEL 3
    	    	    	    	    	    	LCD_Clear();
    	    	    	    	    	    	LCD_GoTo(2,0);
    	    	    	    	    	    	LCD_WriteText("LEVEL 3");
    	    	    	    	    	    	_delay_ms(500);
    	    	    	    	PORTB ^= (1<<PORTB4);
    	    	    	    	    	_delay_ms(500);
    	    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    	    	    	PORTB ^= (1<<PORTB5);
    	    	    	    	    	_delay_ms(500);
    	    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    	    			PORTB ^= (1<<PORTB3);
    	    	    	    			_delay_ms(500);
    	    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    	    			 i = 0;
    	    	    	    			int es3[3];
    	    	    	    			 option=false;
    	    	    	    			while(i<4){
    	    	    	    				if(i==3){
    	    	    	    					if(es3[0]==2){
    	    	    	    						if(es3[1]==3){
    	    	    	    							if(es3[2]==1){
    	    	    	    												option=true;
    	    	    	    							}
    	    	    	    						}
    	    	    	    					}
    	    	    	    					if(option==true){
    	    	    	    						LCD_Clear();
    	    	    	    						LCD_GoTo(2,0);
    	    	    	    						LCD_WriteText("COMPLETED LVL3");
    	    	    	    						_delay_ms(1000);
        	    	    	    					i++;
    	    	    	    					}
    	    	    	    					else{
    	    	    	    						LCD_Clear();
    	    	    	    						LCD_GoTo(2,0);
    	    	    	    						LCD_WriteText("GAME OVER");
    	    	    	    						_delay_ms(500);

    	    	    	    					}
    	    	    	    				}


    	    	    	    				else if (!(PIND & 1<<PIND3)){
    	    	    	    	    				es3[i]=3;
    	    	    	    	    				i++;
    	    	    	    	    				LCD_Clear();
    	    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    	    				            LCD_WriteText("SELECTED N1");
    	    	    	    	    				            _delay_ms(500);
    	    	    	    	    			}
    	    	    	    	    			else if (!(PIND & 1<<PIND2)){
    	    	    	    	    				es3[i]=2;
    	    	    	    	    				i++;
    	    	    	    	    				LCD_Clear();
    	    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    	    				            LCD_WriteText("SELECTED N2");
    	    	    	    	    				            _delay_ms(500);
    	    	    	    	    			}
    	    	    	    	    			else if (!(PIND & 1<<PIND1)){
    	    	    	    	    				es3[i]=1;
    	    	    	    	    				i++;
    	    	    	    	    				LCD_Clear();
    	    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    	    				            LCD_WriteText("SELECTED N3");
    	    	    	    	    				            _delay_ms(500);
    	    	    	    	    			}
    	    	    	    	    			else if (!(PIND & 1<<PIND0)){
    	    	    	    	    				es3[i]=0;
    	    	    	    	    				i++;
    	    	    	    	    				LCD_Clear();
    	    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    	    				            LCD_WriteText("SELECTED N4");
    	    	    	    	    				            _delay_ms(500);
    	    	    	    	    			}

    	    	    	    	    }



    	//LEVEL 4
    	    	    	    	    	LCD_Clear();
    	    	    	    	    	LCD_GoTo(2,0);
    	    	    	    	    	LCD_WriteText("LEVEL 4");
    	    	    	    	    	_delay_ms(500);
    	    	    	PORTB ^= (1<<PORTB4);
    	    	    	    	_delay_ms(500);
    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    	    	PORTB ^= (1<<PORTB5);
    	    	    	    	_delay_ms(500);
    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    			PORTB ^= (1<<PORTB3);
    	    	    			_delay_ms(500);
    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    			PORTB ^= (1<<PORTB2);
    	    	    			_delay_ms(500);
    	    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    			 i = 0;
    	    	    			int es4[4];
    	    	    			 option=false;
    	    	    			while(i<5){
    	    	    				if(i==4){
    	    	    					if(es4[0]==2){
    	    	    						if(es4[1]==3){
    	    	    							if(es4[2]==1){
    	    	    								if(es4[3]==0){
    	    	    												option=true;
    	    	    								}
    	    	    							}
    	    	    						}
    	    	    					}
    	    	    					if(option==true){
    	    	    						LCD_Clear();
    	    	    						LCD_GoTo(2,0);
    	    	    						LCD_WriteText("COMPLETED LVL4");
    	    	    						_delay_ms(1000);
        	    	    					i++;
    	    	    					}
    	    	    					else{
    	    	    						LCD_Clear();
    	    	    						LCD_GoTo(2,0);
    	    	    						LCD_WriteText("GAME OVER");
    	    	    						_delay_ms(500);

    	    	    					}
    	    	    				}


    	    	    				else if (!(PIND & 1<<PIND3)){
    	    	    	    				es4[i]=3;
    	    	    	    				i++;
    	    	    	    				LCD_Clear();
    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    				            LCD_WriteText("SELECTED N1");
    	    	    	    				            _delay_ms(500);
    	    	    	    			}
    	    	    	    			else if (!(PIND & 1<<PIND2)){
    	    	    	    				es4[i]=2;
    	    	    	    				i++;
    	    	    	    				LCD_Clear();
    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    				            LCD_WriteText("SELECTED N2");
    	    	    	    				            _delay_ms(500);
    	    	    	    			}
    	    	    	    			else if (!(PIND & 1<<PIND1)){
    	    	    	    				es4[i]=1;
    	    	    	    				i++;
    	    	    	    				LCD_Clear();
    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    				            LCD_WriteText("SELECTED N3");
    	    	    	    				            _delay_ms(500);
    	    	    	    			}
    	    	    	    			else if (!(PIND & 1<<PIND0)){
    	    	    	    				es4[i]=0;
    	    	    	    				i++;
    	    	    	    				LCD_Clear();
    	    	    	    				            LCD_GoTo(2,0);
    	    	    	    				            LCD_WriteText("SELECTED N4");
    	    	    	    				            _delay_ms(500);
    	    	    	    			}

    	    	    	    }





    	//LEVEL 5
    	    	    	    	LCD_Clear();
    	    	    	    	LCD_GoTo(2,0);
    	    	    	    	LCD_WriteText("LEVEL 5");
    	    	    	    	_delay_ms(500);
    	    	PORTB ^= (1<<PORTB4);
    	    	    	_delay_ms(500);
    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	    	PORTB ^= (1<<PORTB5);
    	    	    	_delay_ms(500);
    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    			PORTB ^= (1<<PORTB3);
    	    			_delay_ms(500);
    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    			PORTB ^= (1<<PORTB2);
    	    			_delay_ms(500);
    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    			PORTB ^= (1<<PORTB3);
    	    			_delay_ms(500);
    	    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    			 i = 0;
    	    			int es5[5];
    	    			 option=false;
    	    			while(i<6){
    	    				if(i==5){
    	    					if(es5[0]==2){
    	    						if(es5[1]==3){
    	    							if(es5[2]==1){
    	    								if(es5[3]==0){
    	    									if(es5[4]==1){
    	    												option=true;
    	    									}
    	    								}
    	    							}
    	    						}
    	    					}
    	    					if(option==true){
    	    						LCD_Clear();
    	    						LCD_GoTo(2,0);
    	    						LCD_WriteText("COMPLETED LVL5");
    	    						_delay_ms(1000);
        	    					i++;
    	    					}
    	    					else{
    	    						LCD_Clear();
    	    						LCD_GoTo(2,0);
    	    						LCD_WriteText("GAME OVER");
    	    						_delay_ms(500);

    	    					}
    	    				}


    	    				else if (!(PIND & 1<<PIND3)){
    	    	    				es5[i]=3;
    	    	    				i++;
    	    	    				LCD_Clear();
    	    	    				            LCD_GoTo(2,0);
    	    	    				            LCD_WriteText("SELECTED N1");
    	    	    				            _delay_ms(500);
    	    	    			}
    	    	    			else if (!(PIND & 1<<PIND2)){
    	    	    				es5[i]=2;
    	    	    				i++;
    	    	    				LCD_Clear();
    	    	    				            LCD_GoTo(2,0);
    	    	    				            LCD_WriteText("SELECTED N2");
    	    	    				            _delay_ms(500);
    	    	    			}
    	    	    			else if (!(PIND & 1<<PIND1)){
    	    	    				es5[i]=1;
    	    	    				i++;
    	    	    				LCD_Clear();
    	    	    				            LCD_GoTo(2,0);
    	    	    				            LCD_WriteText("SELECTED N3");
    	    	    				            _delay_ms(500);
    	    	    			}
    	    	    			else if (!(PIND & 1<<PIND0)){
    	    	    				es5[i]=0;
    	    	    				i++;
    	    	    				LCD_Clear();
    	    	    				            LCD_GoTo(2,0);
    	    	    				            LCD_WriteText("SELECTED N4");
    	    	    				            _delay_ms(500);
    	    	    			}

    	    	    }



    	//LEVEL 6
    	    	    	LCD_Clear();
    	    	    	LCD_GoTo(2,0);
    	    	    	LCD_WriteText("LEVEL 6");
    	    	    	_delay_ms(500);
    	PORTB ^= (1<<PORTB4);
    	    	_delay_ms(500);
    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	PORTB ^= (1<<PORTB5);
    	    	_delay_ms(500);
    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    			PORTB ^= (1<<PORTB3);
    			_delay_ms(500);
    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    			PORTB ^= (1<<PORTB2);
    			_delay_ms(500);
    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    			PORTB ^= (1<<PORTB3);
    			_delay_ms(500);
    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	    	PORTB ^= (1<<PORTB4);
    	    	_delay_ms(500);
    			PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    			 i = 0;
    			int es6[6];
    			 option=false;
    			while(i<7){
    				if(i==6){
    					if(es6[0]==2){
    						if(es6[1]==3){
    							if(es6[2]==1){
    								if(es6[3]==0){
    									if(es6[4]==1){
    										if(es6[5]==2){
    												option=true;
    										}
    									}
    								}
    							}
    						}
    					}
    					if(option==true){
    						LCD_Clear();
    						LCD_GoTo(2,0);
    						LCD_WriteText("COMPLETED LVL 6");
    						_delay_ms(1000);
        					i++;
    					}
    					else{
    						LCD_Clear();
    						LCD_GoTo(2,0);
    						LCD_WriteText("GAME OVER");
    						_delay_ms(500);

    					}
    				}


    				else if (!(PIND & 1<<PIND3)){
    	    				es6[i]=3;
    	    				i++;
    	    				LCD_Clear();
    	    				            LCD_GoTo(2,0);
    	    				            LCD_WriteText("SELECTED N1");
    	    				            _delay_ms(500);
    	    			}
    	    			else if (!(PIND & 1<<PIND2)){
    	    				es6[i]=2;
    	    				i++;
    	    				LCD_Clear();
    	    				            LCD_GoTo(2,0);
    	    				            LCD_WriteText("SELECTED N2");
    	    				            _delay_ms(500);
    	    			}
    	    			else if (!(PIND & 1<<PIND1)){
    	    				es6[i]=1;
    	    				i++;
    	    				LCD_Clear();
    	    				            LCD_GoTo(2,0);
    	    				            LCD_WriteText("SELECTED N3");
    	    				            _delay_ms(500);
    	    			}
    	    			else if (!(PIND & 1<<PIND0)){
    	    				es6[i]=0;
    	    				i++;
    	    				LCD_Clear();
    	    				            LCD_GoTo(2,0);
    	    				            LCD_WriteText("SELECTED N4");
    	    				            _delay_ms(500);
    	    			}

    	    }



    	//LEVEL 7
    	    	LCD_Clear();
    	    	LCD_GoTo(2,0);
    	    	LCD_WriteText("LEVEL 7");
    	    	_delay_ms(500);
    	PORTB ^= (1<<PORTB4);
    	_delay_ms(500);
		PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	PORTB ^= (1<<PORTB5);
    	_delay_ms(500);
		PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
		PORTB ^= (1<<PORTB3);
		_delay_ms(500);
		PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
		PORTB ^= (1<<PORTB2);
		_delay_ms(500);
		PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
		PORTB ^= (1<<PORTB3);
		_delay_ms(500);
		PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
    	PORTB ^= (1<<PORTB4);
    	_delay_ms(500);
		PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
		PORTB ^= (1<<PORTB2);
		_delay_ms(500);
		PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) | (1<<PORTB5);
		  i = 0;
		 int es7[7];
		 option=false;
		while(i<8){
			if(i==7){
				if(es7[0]==2){
					if(es7[1]==3){
						if(es7[2]==1){
							if(es7[3]==0){
								if(es7[4]==1){
									if(es7[5]==2){
										if(es7[6]==0){
											option=true;
										}
									}
								}
							}
						}
					}
				}
				if(option==true){
					LCD_Clear();
					LCD_GoTo(2,0);
					LCD_WriteText("COMPLETED LVL7");
					_delay_ms(1000);
					i++;
				}
				else{
					LCD_Clear();
					LCD_GoTo(2,0);
					LCD_WriteText("GAME OVER");
					_delay_ms(500);

				}
			}


			else if (!(PIND & 1<<PIND3)){
    				es7[i]=3;
    				i++;
    				LCD_Clear();
    				            LCD_GoTo(2,0);
    				            LCD_WriteText("SELECTED N1");
    				            _delay_ms(500);
    			}
    			else if (!(PIND & 1<<PIND2)){
    				es7[i]=2;
    				i++;
    				LCD_Clear();
    				            LCD_GoTo(2,0);
    				            LCD_WriteText("SELECTED N2");
    				            _delay_ms(500);
    			}
    			else if (!(PIND & 1<<PIND1)){
    				es7[i]=1;
    				i++;
    				LCD_Clear();
    				            LCD_GoTo(2,0);
    				            LCD_WriteText("SELECTED N3");
    				            _delay_ms(500);
    			}
    			else if (!(PIND & 1<<PIND0)){
    				es7[i]=0;
    				i++;
    				LCD_Clear();
    				            LCD_GoTo(2,0);
    				            LCD_WriteText("SELECTED N4");
    				            _delay_ms(500);
    			}

    }

		LCD_Clear();
		LCD_GoTo(2,0);
		LCD_WriteText("YOU WIN");
		_delay_ms(500);
}
