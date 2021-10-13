package com.codereview.comparable.examples.controller;

import java.io.IOException;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import com.codereview.comparable.examples.service.ComparatorImage;
import com.codereview.comparable.examples.util.FileUtil;

@RestController
public class ComparatorController {

	@Autowired
	private ComparatorImage compareImageService;

	@GetMapping(value = "/compare", consumes = MediaType.MULTIPART_FORM_DATA_VALUE)
	public String compareImages(@RequestParam MultipartFile imagen1, @RequestParam MultipartFile imagen2)
			throws IllegalStateException, IOException {
		return compareImageService.compareImage(FileUtil.multipartFileToFile(imagen1),
				FileUtil.multipartFileToFile(imagen2));
	}

}
