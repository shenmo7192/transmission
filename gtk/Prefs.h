// This file copyright (C) 2005-2022 Transmission authors and contributors.
// It may be used under the MIT (SPDX: MIT) license.
// License text can be found in the licenses/ folder.

#pragma once

#include <inttypes.h>
#include <string>
#include <vector>

#include <libtransmission/transmission.h> /* tr_variant, tr_session */
#include <libtransmission/quark.h>

void gtr_pref_init(std::string const& config_dir);

int64_t gtr_pref_int_get(tr_quark const key);
void gtr_pref_int_set(tr_quark const key, int64_t value);

double gtr_pref_double_get(tr_quark const key);
void gtr_pref_double_set(tr_quark const key, double value);

bool gtr_pref_flag_get(tr_quark const key);
void gtr_pref_flag_set(tr_quark const key, bool value);

std::vector<std::string> gtr_pref_strv_get(tr_quark const key);

std::string gtr_pref_string_get(tr_quark const key);
void gtr_pref_string_set(tr_quark const key, std::string const& value);

void gtr_pref_save(tr_session*);
tr_variant* gtr_pref_get_all();
