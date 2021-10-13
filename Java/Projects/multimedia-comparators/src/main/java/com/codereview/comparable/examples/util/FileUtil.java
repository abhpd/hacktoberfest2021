package com.codereview.comparable.examples.util;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import org.springframework.web.multipart.MultipartFile;

public class FileUtil {
	
	private static String path = "src/main/resources/static/";

	public static File multipartFileToFile(MultipartFile imagen1) throws IOException {
		File img1 = new File(path.concat(imagen1.getOriginalFilename()));
		try (OutputStream os = new FileOutputStream(img1)) {
			os.write(imagen1.getBytes());
		}
		return img1;
	}

}
