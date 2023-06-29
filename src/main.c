// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2023 Brian Starkey <stark3y@gmail.com>
// Gustavo Diaz <intgusd@gmail.com>

#include <stdio.h>
#include <string.h>

#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"

#include "bt_hid.h"

// This is an example of how to parse button information

#define BUTTON_A 1
#define BUTTON_B 2
#define BUTTON_X 4
#define BUTTON_Y 8


void main(void) {
	stdio_init_all();

	sleep_ms(1000);

	multicore_launch_core1(bt_main);
	// Wait for init (should do a handshake with the fifo here?)
	sleep_ms(1000);

	struct bt_hid_state state;
	for ( ;; ) {
		sleep_ms(20);
		bt_hid_get_latest(&state);
		// Use the state of the xbox controller here
	
		if (state.buttons & BUTTON_A) {
			// Button A is pressed
			printf("Button A is pressed\n");
		}

		if (state.buttons & BUTTON_B) {
			// Button B is pressed
			printf("Button B is pressed\n");
		}

		if (state.buttons & BUTTON_X) {
			// Button X is pressed
			printf("Button X is pressed\n");
		}

		if (state.buttons & BUTTON_Y) {
			// Button Y is pressed
			printf("Button Y is pressed\n");
		}

		// Check combinations of buttons
		if ((state.buttons & (BUTTON_A | BUTTON_X)) == (BUTTON_A | BUTTON_X)) {
			// Combination of buttons A and X is pressed
			printf("Buttons A and X are pressed\n");
		}
	
		// Print for debugging purposes to USB serial monitor
		// printf("buttons: %d, l: %d,%d, r: %d,%d, l2,r2: %d,%d hat: %d\n",
		// 		state.buttons, state.lx, state.ly, state.rx, state.ry,
		// 		state.l2, state.r2, state.hat);

	}
}
