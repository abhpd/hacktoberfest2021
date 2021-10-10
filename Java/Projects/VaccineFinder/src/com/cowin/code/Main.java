package com.cowin.code;

import java.io.IOException;

public class Main {
	public static void main(String[] args) throws InterruptedException, IOException {

		VaccineService vaccineService = new VaccineService();
		while (true) {
			boolean isAvailable = vaccineService.isAvailable();

			if (isAvailable) {

				// Todo:notify
				vaccineService.notifyOnWindows();
			}

			// calls after X minutes
			Thread.sleep(5 * 60 * 1000);
		}

	}
}
