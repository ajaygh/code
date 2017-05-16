public class MediaAdaptor implements MediaPlayer {
    AdvancedMediaPlayer advancedMediaPlayer;
    public MediaAdaptor(String mediaType){
        if(mediaType.equalsIgnoreCase("vlc")){
            advancedMediaPlayer = new VlcPlayer();
        }else if(mediaType.equalsIgnoreCase("mp4")){
            advancedMediaPlayer = new Mp4Player();
        }
    }
    @Override
    public void play(String fileType, String fileName) {
        if(fileType.equalsIgnoreCase("vlc")){
            advancedMediaPlayer.playVlc(fileName);

        }else if(fileType.equalsIgnoreCase("mp4")){
            advancedMediaPlayer.playMp4(fileName);

        }
    }
}
