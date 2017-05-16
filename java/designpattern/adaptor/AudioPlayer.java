public class AudioPlayer implements MediaPlayer {
    MediaAdaptor mediaAdaptor;

    @Override
    public void play(String fileType, String fileName) {
        if(fileType.equalsIgnoreCase("mp3")){
            System.out.println("Playing using mp3 player filename : "+ fileName);
        
        }else if(fileType.equalsIgnoreCase("mp4") ||
        fileType.equalsIgnoreCase("vlc")){
            mediaAdaptor = new MediaAdaptor(fileType);
            mediaAdaptor.play(fileType, fileName);
        }else{
            System.out.println("Unsupported format.");
        }
    }
}
