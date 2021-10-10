package com.cowin.code;

import java.io.IOException;
import java.util.List;

import org.apache.http.Header;
import org.apache.http.HttpEntity;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

import com.fasterxml.jackson.databind.DeserializationFeature;
import com.fasterxml.jackson.databind.ObjectMapper;

public class VaccineService {

    private final CloseableHttpClient httpClient = HttpClients.createDefault();
    ObjectMapper objectMapper = new ObjectMapper().configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);


    public boolean isAvailable() {
       // Scanner sc = new Scanner(System.in);
       // String pincode = sc.nextLine();

        //Enter Pincode
        HttpGet request = new HttpGet(
                "https://cdn-api.co-vin.in/api/v2/appointment/sessions/public/calendarByPin?pincode=201005&date=10-10-2021");

        request.addHeader("authority", "cdn-api.co-vin.in");
        request.addHeader("sec-ch-ua", "\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"90\", \"Google Chrome\";v=\"90\"");
        request.addHeader("accept", "application/json, text/plain, */*");
        request.addHeader("sec-ch-ua-mobile", "?0");
        request.addHeader("user-agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36");
        request.addHeader("origin", "https://www.cowin.gov.in");
        request.addHeader("sec-fetch-mode", "cors");
        request.addHeader("sec-fetch-dest", "empty");
        request.addHeader("referer", "https://www.cowin.gov.in/");
        request.addHeader("accept-language", "en-GB,en-US;q=0.9,en;q=0.8");
        request.addHeader("if-none-match", "W/\"755-kSDAGwS0dhuJu/VuZ3UJpZ2STnc\"");

        try (CloseableHttpResponse response = httpClient.execute(request)) {

            // Get HttpResponse Status
            System.out.println(response.getStatusLine().toString());

            HttpEntity entity = response.getEntity();
            Header headers = entity.getContentType();

            if (entity != null) {
                // return it as a String
                String result = EntityUtils.toString(entity);
                
                Root root = objectMapper.readValue(result, Root.class);

                boolean isAvailable = false;
                for(int i = 0; i < root.centers.size(); i++){
                    List<Session> sessions = root.centers.get(i).getSessions();
                    for(int j = 0; j < sessions.size(); j++){
                        Session session = sessions.get(j);
                        if (session.min_age_limit == 45 && session.available_capacity > 0) {
                            isAvailable = true;
                        }
                    }
                }

                
                System.out
                        .println(isAvailable ? "Vaccine is available.."
                                : "Vaccine is NOT available..try again");
                return isAvailable;
            }

        } catch (ClientProtocolException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }

    public void notifyOnWindows() throws IOException {
        // Runtime.getRuntime().exec(String.format("terminal-notifier -message
        // Vaccine_Available"));
    }
}
