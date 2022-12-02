#include "include/flutter_volume_controller/method_handler.h"
#include "include/flutter_volume_controller/constants.h"

FlMethodResponse *get_volume(AlsaCard *card) {
    gdouble volume;

    if (!alsa_card_get_volume(card, &volume))
        return FL_METHOD_RESPONSE(fl_method_error_response_new(ERROR_CODE_GET_VOLUME, ERROR_MSG_GET_VOLUME, NULL));

    g_autoptr(FlValue) res = fl_value_new_float(volume);
    return FL_METHOD_RESPONSE(fl_method_success_response_new(res));
}

FlMethodResponse *set_volume(AlsaCard *card, gfloat volume) {
    if (!alsa_card_set_volume(card, volume, 0))
        return FL_METHOD_RESPONSE(fl_method_error_response_new(ERROR_CODE_SET_VOLUME, ERROR_MSG_SET_VOLUME, NULL));

    return FL_METHOD_RESPONSE(fl_method_success_response_new(NULL));
}

FlMethodResponse *raise_volume(AlsaCard *card, gfloat step) {
    if (!alsa_card_set_volume(card, step, 1))
        return FL_METHOD_RESPONSE(fl_method_error_response_new(ERROR_CODE_RAISE_VOLUME, ERROR_MSG_RAISE_VOLUME, NULL));

    return FL_METHOD_RESPONSE(fl_method_success_response_new(NULL));
}

FlMethodResponse *lower_volume(AlsaCard *card, gfloat step) {
    if (!alsa_card_set_volume(card, step, -1))
        return FL_METHOD_RESPONSE(fl_method_error_response_new(ERROR_CODE_LOWER_VOLUME, ERROR_MSG_LOWER_VOLUME, NULL));

    return FL_METHOD_RESPONSE(fl_method_success_response_new(NULL));
}

FlMethodResponse *get_mute(AlsaCard *card) {
    gboolean muted;

    if (!alsa_card_is_muted(card, &muted))
        return FL_METHOD_RESPONSE(fl_method_error_response_new(ERROR_CODE_GET_MUTE, ERROR_MSG_GET_MUTE, NULL));

    g_autoptr(FlValue) res = fl_value_new_bool(muted);
    return FL_METHOD_RESPONSE(fl_method_success_response_new(res));
}

FlMethodResponse *set_mute(AlsaCard *card, gboolean muted) {
    if (!alsa_card_set_mute(card, muted))
        return FL_METHOD_RESPONSE(fl_method_error_response_new(ERROR_CODE_SET_MUTE, ERROR_MSG_SET_MUTE, NULL));

    return FL_METHOD_RESPONSE(fl_method_success_response_new(NULL));
}

FlMethodResponse *toggle_mute(AlsaCard *card) {
    if (!alsa_card_toggle_mute(card))
        return FL_METHOD_RESPONSE(fl_method_error_response_new(ERROR_CODE_TOGGLE_MUTE, ERROR_MSG_TOGGLE_MUTE, NULL));

    return FL_METHOD_RESPONSE(fl_method_success_response_new(NULL));
}
