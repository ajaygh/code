public class AdaptorPatternDemo {
    public static void main(String[] args) {
        AudioPlayer audioPlayer = new AudioPlayer();
        audioPlayer.play("mp3", "guide.mp3");
        audioPlayer.play("mp4", "don.mp4");
        audioPlayer.play("vlc", "kjbb.vlc");
        audioPlayer.play("mp3", "guide.mp3");
    }
}
