package com.codereview.comparable.examples.service;

import java.io.File;
import java.io.FileReader;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;

@Service
public class ComparatorImage {

	private static Logger LOGGER = LoggerFactory.getLogger(ComparatorImage.class);

	public String compareImage(File imagen1, File imagen2) {
		var message = "";
		try (FileReader fr1 = new FileReader(imagen1); FileReader fr2 = new FileReader(imagen2)) {
			var found = false;
			while (true) {
				var pix1 = fr1.read();
				var pix2 = fr2.read();
				// we compare pixel by pixel
				if (pix1 != pix2)
					break;
				// if one of the two is -1 the file is finished
				if (pix1 == -1) {
					found = true;
					break;
				}
			}
			if (found) {
				message = "the images are the same";
				LOGGER.info(message);
			} else {
				message = "the images are not the same";
				LOGGER.info(message);
			}
			return message;
		} catch (Exception e) {
			e.printStackTrace();
			return !message.isEmpty() ? message : e.getMessage();
		} finally {
			imagen1.delete();
			imagen2.delete();
		}
	}

}
