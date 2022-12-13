package com.yosemiteyss.flutter_volume_controller

import android.media.AudioManager

enum class AudioStream {
    SYSTEM, MUSIC, NOTIFICATION;

    val streamType: Int
        get() {
            return when (this) {
                SYSTEM -> AudioManager.STREAM_SYSTEM
                MUSIC -> AudioManager.STREAM_MUSIC
                NOTIFICATION -> AudioManager.STREAM_NOTIFICATION
            }
        }
}
