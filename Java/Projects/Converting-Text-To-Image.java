class TextToImageDemo{
 
public static void main(String[] args) throws IOException{
        
        //create String object to be converted to image
       String sampleText = "SAMPLE TEXT";
 
        //Image file name
       String fileName = "Image";
        
        //create a File Object
        File newFile = new File("./" + fileName + ".jpeg");
         
        //create the font you wish to use
        Font font = new Font("Tahoma", Font.PLAIN, 11);
        
        //create the FontRenderContext object which helps us to measure the text
        FontRenderContext frc = new FontRenderContext(null, true, true);
         
        //get the height and width of the text
        Rectangle2D bounds = font.getStringBounds(sampleText, frc);
        int w = (int) bounds.getWidth();
        int h = (int) bounds.getHeight();
        
        //create a BufferedImage object
       BufferedImage image = new BufferedImage(w, h,   BufferedImage.TYPE_INT_RGB);
        
        //calling createGraphics() to get the Graphics2D
        Graphics2D g = image.createGraphics();
        
        //set color and other parameters
        g.setColor(Color.WHITE);
        g.fillRect(0, 0, w, h);
        g.setColor(Color.BLACK);
        g.setFont(font);
             
       g.drawString(sampleText, (float) bounds.getX(), (float) -bounds.getY());
       
      //releasing resources
      g.dispose();
       
        //creating the file
       ImageIO.write(image, "jpeg", fileName);
 }
}
