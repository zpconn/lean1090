import Spec.StandardExamples

/-!
# Complete result fixtures for every published complete message

These literal expected messages supplement the independently sourced assertions
in Spec.StandardExamples. Fields not supplied by Sun are captured project-specific
regression expectations, NOT attributed to the published source. Capture used a
one-time evaluation of the current reference decoder; these fixed Lean terms are
then parsed and checked by the kernel. A snapshot alone cannot independently
validate the decoder. The separate StandardExamples assertions provide that anchor.

No expected term below calls a decoder, encoder, report constructor helper,
inference routine, or semantic projection: each is a complete literal data value.
See docs/STANDARD-EXAMPLES.md for provenance, coverage, and source contradictions.
-/
namespace Lean1090.Spec.StandardFullExamples
open StandardExamples

set_option maxRecDepth 100000
set_option maxHeartbeats 0

/-- Complete literal regression snapshot for the `quick_startBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def quick_startExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0x451dbd#24 0x9905b501800400#56,
      parity := 0x5979c5#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x451dbd#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 1224,
        fields := [
          {
            name := "tc",
            code := 19
          },
          {
            name := "subtype",
            code := 1
          },
          {
            name := "intent_change",
            code := 0
          },
          {
            name := "ifr_capability",
            code := 0
          },
          {
            name := "NACv",
            code := 0
          },
          {
            name := "ew_sign",
            code := 1
          },
          {
            name := "ew_velocity",
            code := 437
          },
          {
            name := "ns_sign",
            code := 0
          },
          {
            name := "ns_velocity",
            code := 12
          },
          {
            name := "vrate_source",
            code := 0
          },
          {
            name := "vrate_sign",
            code := 0
          },
          {
            name := "vertical_rate_code",
            code := 1
          },
          {
            name := "reserved",
            code := 0
          },
          {
            name := "gnss_sign",
            code := 0
          },
          {
            name := "geo_minus_baro_code",
            code := 0
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 19),
          ("subtype",
          some 1),
          ("intent_change",
          some 0),
          ("ifr_capability",
          some 0),
          ("NACv",
          some 0),
          ("ew_sign",
          some 1),
          ("ew_velocity",
          some 437),
          ("ns_sign",
          some 0),
          ("ns_velocity",
          some 12),
          ("vrate_source",
          some 0),
          ("vrate_sign",
          some 0),
          ("vertical_rate_code",
          some 1),
          ("reserved",
          some 0),
          ("gnss_sign",
          some 0),
          ("geo_minus_baro_code",
          some 0)
        ],
        standardValues := [
          ("east_velocity",
          some (-436)),
          ("north_velocity",
          some 11),
          ("vertical_rate",
          some 0),
          ("geo_minus_baro",
          none),
          ("airspeed",
          none)
        ],
        oracleValues := [
          ("east_velocity",
          some (-436)),
          ("north_velocity",
          some 11),
          ("vertical_rate",
          some 0),
          ("geo_minus_baro",
          none),
          ("airspeed",
          none)
        ],
        standardLabels := [
          ("vrate_src",
          some "GNSS"),
          ("airspeed_type",
          none)
        ],
        oracleLabels := [
          ("vrate_src",
          some "barometric"),
          ("airspeed_type",
          none)
        ],
        standardFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.hypot64 (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-436))) (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 11))),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.atan2_64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-436)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 11)) (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((884279719003555 : Rat) / 281474976710656)))))),
            missing := Presentation.Missing.null
          }
        ],
        oracleFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.hypot64 (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-436))) (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 11))),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.atan2_64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-436)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 11)) (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((884279719003555 : Rat) / 281474976710656)))))),
            missing := Presentation.Missing.null
          }
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `quick_start_frame` and its semantic checks. -/
theorem quick_start_full :
    Lean1090.Spec.decode quick_startBytes = quick_startExpected := by
  decide +kernel

example : Lean1090.Spec.decode quick_startBytes = quick_startExpected := quick_start_full

/-- Complete literal regression snapshot for the `identificationBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def identificationExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0x4840d6#24 0x202cc371c32ce0#56,
      parity := 0x576098#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x4840d6#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 256,
        fields := [
          {
            name := "tc",
            code := 4
          },
          {
            name := "category",
            code := 0
          },
          {
            name := "char0",
            code := 11
          },
          {
            name := "char1",
            code := 12
          },
          {
            name := "char2",
            code := 13
          },
          {
            name := "char3",
            code := 49
          },
          {
            name := "char4",
            code := 48
          },
          {
            name := "char5",
            code := 50
          },
          {
            name := "char6",
            code := 51
          },
          {
            name := "char7",
            code := 32
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 4),
          ("category",
          some 0),
          ("char0",
          some 11),
          ("char1",
          some 12),
          ("char2",
          some 13),
          ("char3",
          some 49),
          ("char4",
          some 48),
          ("char5",
          some 50),
          ("char6",
          some 51),
          ("char7",
          some 32)
        ],
        standardValues := [
          
        ],
        oracleValues := [
          
        ],
        standardLabels := [
          ("callsign",
          some "KLM1023"),
          ("wake_vortex",
          some "n/a")
        ],
        oracleLabels := [
          ("callsign",
          some "KLM1023"),
          ("wake_vortex",
          some "n/a")
        ],
        standardFloats := [
          
        ],
        oracleFloats := [
          
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `identification_frame` and its semantic checks. -/
theorem identification_full :
    Lean1090.Spec.decode identificationBytes = identificationExpected := by
  decide +kernel

example : Lean1090.Spec.decode identificationBytes = identificationExpected := identification_full

/-- Complete literal regression snapshot for the `airborne_evenBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def airborne_evenExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0x40621d#24 0x58c382d690c8ac#56,
      parity := 0x2863a7#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x40621d#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 38000),
      identity := none,
      adsb := some {
        kind := 704,
        fields := [
          {
            name := "tc",
            code := 11
          },
          {
            name := "ss",
            code := 0
          },
          {
            name := "saf_or_nicb",
            code := 0
          },
          {
            name := "altitude_code",
            code := 3128
          },
          {
            name := "time_sync",
            code := 0
          },
          {
            name := "parity",
            code := 0
          },
          {
            name := "lat_cpr",
            code := 93000
          },
          {
            name := "lon_cpr",
            code := 51372
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 11),
          ("ss",
          some 0),
          ("saf_or_nicb",
          some 0),
          ("altitude_code",
          some 3128),
          ("time_sync",
          some 0),
          ("parity",
          some 0),
          ("lat_cpr",
          some 93000),
          ("lon_cpr",
          some 51372)
        ],
        standardValues := [
          ("NUCp",
          some 7),
          ("NICb",
          some 0),
          ("altitude_feet",
          some 38000),
          ("height_metres",
          none)
        ],
        oracleValues := [
          ("NUCp",
          some 7),
          ("NICb",
          some 0),
          ("altitude_feet",
          some 38000)
        ],
        standardLabels := [
          ("source",
          some "barometric")
        ],
        oracleLabels := [
          ("source",
          some "barometric")
        ],
        standardFloats := [
          
        ],
        oracleFloats := [
          
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `airborne_even_frame` and its semantic checks. -/
theorem airborne_even_full :
    Lean1090.Spec.decode airborne_evenBytes = airborne_evenExpected := by
  decide +kernel

example : Lean1090.Spec.decode airborne_evenBytes = airborne_evenExpected := airborne_even_full

/-- Complete literal regression snapshot for the `airborne_oddBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def airborne_oddExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0x40621d#24 0x58c386435cc412#56,
      parity := 0x692ad6#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x40621d#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 38000),
      identity := none,
      adsb := some {
        kind := 704,
        fields := [
          {
            name := "tc",
            code := 11
          },
          {
            name := "ss",
            code := 0
          },
          {
            name := "saf_or_nicb",
            code := 0
          },
          {
            name := "altitude_code",
            code := 3128
          },
          {
            name := "time_sync",
            code := 0
          },
          {
            name := "parity",
            code := 1
          },
          {
            name := "lat_cpr",
            code := 74158
          },
          {
            name := "lon_cpr",
            code := 50194
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 11),
          ("ss",
          some 0),
          ("saf_or_nicb",
          some 0),
          ("altitude_code",
          some 3128),
          ("time_sync",
          some 0),
          ("parity",
          some 1),
          ("lat_cpr",
          some 74158),
          ("lon_cpr",
          some 50194)
        ],
        standardValues := [
          ("NUCp",
          some 7),
          ("NICb",
          some 0),
          ("altitude_feet",
          some 38000),
          ("height_metres",
          none)
        ],
        oracleValues := [
          ("NUCp",
          some 7),
          ("NICb",
          some 0),
          ("altitude_feet",
          some 38000)
        ],
        standardLabels := [
          ("source",
          some "barometric")
        ],
        oracleLabels := [
          ("source",
          some "barometric")
        ],
        standardFloats := [
          
        ],
        oracleFloats := [
          
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `airborne_odd_frame` and its semantic checks. -/
theorem airborne_odd_full :
    Lean1090.Spec.decode airborne_oddBytes = airborne_oddExpected := by
  decide +kernel

example : Lean1090.Spec.decode airborne_oddBytes = airborne_oddExpected := airborne_odd_full

/-- Complete literal regression snapshot for the `surface_evenBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def surface_evenExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x4#3 0x484175#24 0x3aab238733c8cd#56,
      parity := 0x4020b1#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x484175#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 448,
        fields := [
          {
            name := "tc",
            code := 7
          },
          {
            name := "movement",
            code := 42
          },
          {
            name := "track_status",
            code := 1
          },
          {
            name := "track",
            code := 50
          },
          {
            name := "time_sync",
            code := 0
          },
          {
            name := "parity",
            code := 0
          },
          {
            name := "lat_cpr",
            code := 115609
          },
          {
            name := "lon_cpr",
            code := 116941
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 7),
          ("movement",
          some 42),
          ("track_status",
          some 1),
          ("track",
          some ((1125 : Rat) / 8)),
          ("time_sync",
          some 0),
          ("parity",
          some 0),
          ("lat_cpr",
          some 115609),
          ("lon_cpr",
          some 116941)
        ],
        standardValues := [
          ("NUCp",
          some 7),
          ("groundspeed",
          some 18)
        ],
        oracleValues := [
          ("NUCp",
          some 7),
          ("groundspeed",
          some 18)
        ],
        standardLabels := [
          
        ],
        oracleLabels := [
          
        ],
        standardFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 18),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 50) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 128)),
            missing := Presentation.Missing.null
          }
        ],
        oracleFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 18),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 50) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 128)),
            missing := Presentation.Missing.null
          }
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `surface_even_frame` and its semantic checks. -/
theorem surface_even_full :
    Lean1090.Spec.decode surface_evenBytes = surface_evenExpected := by
  decide +kernel

example : Lean1090.Spec.decode surface_evenBytes = surface_evenExpected := surface_even_full

/-- Complete literal regression snapshot for the `surface_oddBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def surface_oddExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x4#3 0x484175#24 0x3a8a35323faebd#56,
      parity := 0xac702d#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x484175#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 448,
        fields := [
          {
            name := "tc",
            code := 7
          },
          {
            name := "movement",
            code := 40
          },
          {
            name := "track_status",
            code := 1
          },
          {
            name := "track",
            code := 35
          },
          {
            name := "time_sync",
            code := 0
          },
          {
            name := "parity",
            code := 1
          },
          {
            name := "lat_cpr",
            code := 39199
          },
          {
            name := "lon_cpr",
            code := 110269
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 7),
          ("movement",
          some 40),
          ("track_status",
          some 1),
          ("track",
          some ((1575 : Rat) / 16)),
          ("time_sync",
          some 0),
          ("parity",
          some 1),
          ("lat_cpr",
          some 39199),
          ("lon_cpr",
          some 110269)
        ],
        standardValues := [
          ("NUCp",
          some 7),
          ("groundspeed",
          some 16)
        ],
        oracleValues := [
          ("NUCp",
          some 7),
          ("groundspeed",
          some 16)
        ],
        standardLabels := [
          
        ],
        oracleLabels := [
          
        ],
        standardFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 16),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 35) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 128)),
            missing := Presentation.Missing.null
          }
        ],
        oracleFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 16),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 35) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 128)),
            missing := Presentation.Missing.null
          }
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `surface_odd_frame` and its semantic checks. -/
theorem surface_odd_full :
    Lean1090.Spec.decode surface_oddBytes = surface_oddExpected := by
  decide +kernel

example : Lean1090.Spec.decode surface_oddBytes = surface_oddExpected := surface_odd_full

/-- Complete literal regression snapshot for the `surface_localBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def surface_localExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x4#3 0x484175#24 0x3a9a153237aef0#56,
      parity := 0xf275be#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x484175#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 448,
        fields := [
          {
            name := "tc",
            code := 7
          },
          {
            name := "movement",
            code := 41
          },
          {
            name := "track_status",
            code := 1
          },
          {
            name := "track",
            code := 33
          },
          {
            name := "time_sync",
            code := 0
          },
          {
            name := "parity",
            code := 1
          },
          {
            name := "lat_cpr",
            code := 39195
          },
          {
            name := "lon_cpr",
            code := 110320
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 7),
          ("movement",
          some 41),
          ("track_status",
          some 1),
          ("track",
          some ((1485 : Rat) / 16)),
          ("time_sync",
          some 0),
          ("parity",
          some 1),
          ("lat_cpr",
          some 39195),
          ("lon_cpr",
          some 110320)
        ],
        standardValues := [
          ("NUCp",
          some 7),
          ("groundspeed",
          some 17)
        ],
        oracleValues := [
          ("NUCp",
          some 7),
          ("groundspeed",
          some 17)
        ],
        standardLabels := [
          
        ],
        oracleLabels := [
          
        ],
        standardFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 17),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 33) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 128)),
            missing := Presentation.Missing.null
          }
        ],
        oracleFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 17),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 33) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 128)),
            missing := Presentation.Missing.null
          }
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `surface_local_frame` and its semantic checks. -/
theorem surface_local_full :
    Lean1090.Spec.decode surface_localBytes = surface_localExpected := by
  decide +kernel

example : Lean1090.Spec.decode surface_localBytes = surface_localExpected := surface_local_full

/-- Complete literal regression snapshot for the `velocity_groundBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def velocity_groundExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0x485020#24 0x99440994083817#56,
      parity := 0x5b284f#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x485020#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 1224,
        fields := [
          {
            name := "tc",
            code := 19
          },
          {
            name := "subtype",
            code := 1
          },
          {
            name := "intent_change",
            code := 0
          },
          {
            name := "ifr_capability",
            code := 1
          },
          {
            name := "NACv",
            code := 0
          },
          {
            name := "ew_sign",
            code := 1
          },
          {
            name := "ew_velocity",
            code := 9
          },
          {
            name := "ns_sign",
            code := 1
          },
          {
            name := "ns_velocity",
            code := 160
          },
          {
            name := "vrate_source",
            code := 0
          },
          {
            name := "vrate_sign",
            code := 1
          },
          {
            name := "vertical_rate_code",
            code := 14
          },
          {
            name := "reserved",
            code := 0
          },
          {
            name := "gnss_sign",
            code := 0
          },
          {
            name := "geo_minus_baro_code",
            code := 23
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 19),
          ("subtype",
          some 1),
          ("intent_change",
          some 0),
          ("ifr_capability",
          some 1),
          ("NACv",
          some 0),
          ("ew_sign",
          some 1),
          ("ew_velocity",
          some 9),
          ("ns_sign",
          some 1),
          ("ns_velocity",
          some 160),
          ("vrate_source",
          some 0),
          ("vrate_sign",
          some 1),
          ("vertical_rate_code",
          some 14),
          ("reserved",
          some 0),
          ("gnss_sign",
          some 0),
          ("geo_minus_baro_code",
          some 23)
        ],
        standardValues := [
          ("east_velocity",
          some (-8)),
          ("north_velocity",
          some (-159)),
          ("vertical_rate",
          some (-832)),
          ("geo_minus_baro",
          some 550),
          ("airspeed",
          none)
        ],
        oracleValues := [
          ("east_velocity",
          some (-8)),
          ("north_velocity",
          some (-159)),
          ("vertical_rate",
          some (-832)),
          ("geo_minus_baro",
          some 550),
          ("airspeed",
          none)
        ],
        standardLabels := [
          ("vrate_src",
          some "GNSS"),
          ("airspeed_type",
          none)
        ],
        oracleLabels := [
          ("vrate_src",
          some "barometric"),
          ("airspeed_type",
          none)
        ],
        standardFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.hypot64 (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-8))) (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-159)))),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.atan2_64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-8)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-159))) (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((884279719003555 : Rat) / 281474976710656)))))),
            missing := Presentation.Missing.null
          }
        ],
        oracleFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.hypot64 (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-8))) (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-159)))),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.atan2_64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-8)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-159))) (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((884279719003555 : Rat) / 281474976710656)))))),
            missing := Presentation.Missing.null
          }
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `velocity_ground_frame` and its semantic checks. -/
theorem velocity_ground_full :
    Lean1090.Spec.decode velocity_groundBytes = velocity_groundExpected := by
  decide +kernel

example : Lean1090.Spec.decode velocity_groundBytes = velocity_groundExpected := velocity_ground_full

/-- Complete literal regression snapshot for the `velocity_airBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def velocity_airExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0xa05f21#24 0x9b06b6af189400#56,
      parity := 0xcbc33f#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0xa05f21#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 1240,
        fields := [
          {
            name := "tc",
            code := 19
          },
          {
            name := "subtype",
            code := 3
          },
          {
            name := "intent_change",
            code := 0
          },
          {
            name := "ifr_capability",
            code := 0
          },
          {
            name := "NACv",
            code := 0
          },
          {
            name := "heading_status",
            code := 1
          },
          {
            name := "heading",
            code := 694
          },
          {
            name := "airspeed_type",
            code := 1
          },
          {
            name := "airspeed_code",
            code := 376
          },
          {
            name := "vrate_source",
            code := 1
          },
          {
            name := "vrate_sign",
            code := 1
          },
          {
            name := "vertical_rate_code",
            code := 37
          },
          {
            name := "reserved",
            code := 0
          },
          {
            name := "gnss_sign",
            code := 0
          },
          {
            name := "geo_minus_baro_code",
            code := 0
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 19),
          ("subtype",
          some 3),
          ("intent_change",
          some 0),
          ("ifr_capability",
          some 0),
          ("NACv",
          some 0),
          ("heading_status",
          some 1),
          ("heading",
          some ((15615 : Rat) / 64)),
          ("airspeed_type",
          some 1),
          ("airspeed_code",
          some 376),
          ("vrate_source",
          some 1),
          ("vrate_sign",
          some 1),
          ("vertical_rate_code",
          some 37),
          ("reserved",
          some 0),
          ("gnss_sign",
          some 0),
          ("geo_minus_baro_code",
          some 0)
        ],
        standardValues := [
          ("east_velocity",
          none),
          ("north_velocity",
          none),
          ("vertical_rate",
          some (-2304)),
          ("geo_minus_baro",
          none),
          ("airspeed",
          some 375)
        ],
        oracleValues := [
          ("east_velocity",
          none),
          ("north_velocity",
          none),
          ("vertical_rate",
          some (-2304)),
          ("geo_minus_baro",
          none),
          ("airspeed",
          some 375)
        ],
        standardLabels := [
          ("vrate_src",
          some "barometric"),
          ("airspeed_type",
          some "TAS")
        ],
        oracleLabels := [
          ("vrate_src",
          some "GNSS"),
          ("airspeed_type",
          some "TAS")
        ],
        standardFloats := [
          {
            key := "heading",
            value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 694) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 1024)),
            missing := Presentation.Missing.omit
          }
        ],
        oracleFloats := [
          {
            key := "heading",
            value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 694) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 1024)),
            missing := Presentation.Missing.omit
          }
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `velocity_air_frame` and its semantic checks. -/
theorem velocity_air_full :
    Lean1090.Spec.decode velocity_airBytes = velocity_airExpected := by
  decide +kernel

example : Lean1090.Spec.decode velocity_airBytes = velocity_airExpected := velocity_air_full

/-- Complete literal regression snapshot for the `crc_goodBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def crc_goodExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0x406b90#24 0x2015a678d4d220#56,
      parity := 0xaa4bda#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x406b90#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 256,
        fields := [
          {
            name := "tc",
            code := 4
          },
          {
            name := "category",
            code := 0
          },
          {
            name := "char0",
            code := 5
          },
          {
            name := "char1",
            code := 26
          },
          {
            name := "char2",
            code := 25
          },
          {
            name := "char3",
            code := 56
          },
          {
            name := "char4",
            code := 53
          },
          {
            name := "char5",
            code := 13
          },
          {
            name := "char6",
            code := 8
          },
          {
            name := "char7",
            code := 32
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 4),
          ("category",
          some 0),
          ("char0",
          some 5),
          ("char1",
          some 26),
          ("char2",
          some 25),
          ("char3",
          some 56),
          ("char4",
          some 53),
          ("char5",
          some 13),
          ("char6",
          some 8),
          ("char7",
          some 32)
        ],
        standardValues := [
          
        ],
        oracleValues := [
          
        ],
        standardLabels := [
          ("callsign",
          some "EZY85MH"),
          ("wake_vortex",
          some "n/a")
        ],
        oracleLabels := [
          ("callsign",
          some "EZY85MH"),
          ("wake_vortex",
          some "n/a")
        ],
        standardFloats := [
          
        ],
        oracleFloats := [
          
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `crc_good_frame` and its semantic checks. -/
theorem crc_good_full :
    Lean1090.Spec.decode crc_goodBytes = crc_goodExpected := by
  decide +kernel

example : Lean1090.Spec.decode crc_goodBytes = crc_goodExpected := crc_good_full

/-- Complete literal regression snapshot for the `address_parityBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def address_parityExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB false {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x1838#13
      } 0xca380031440000#56,
      parity := 0xf24177#24
    },
    decoded := {
      crc := 0x3c6dd0#24,
      address := some 0x3c6dd0#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 38000),
      identity := none,
      adsb := none,
      commB := [
        (33,
        {
          kind := 33,
          fields := [
            {
              name := "ac_status",
              code := 1
            },
            {
              name := "reg_char1",
              code := 37
            },
            {
              name := "reg_char2",
              code := 7
            },
            {
              name := "reg_char3",
              code := 0
            },
            {
              name := "reg_char4",
              code := 0
            },
            {
              name := "reg_char5",
              code := 24
            },
            {
              name := "reg_char6",
              code := 40
            },
            {
              name := "reg_char7",
              code := 32
            },
            {
              name := "al_status",
              code := 0
            },
            {
              name := "airline_char1",
              code := 0
            },
            {
              name := "airline_char2",
              code := 0
            }
          ]
        }),
        (64,
        {
          kind := 64,
          fields := [
            {
              name := "mcp_valid",
              code := 1
            },
            {
              name := "selected_mcp",
              code := 2375
            },
            {
              name := "fms_valid",
              code := 0
            },
            {
              name := "selected_fms",
              code := 0
            },
            {
              name := "qnh_valid",
              code := 1
            },
            {
              name := "barometric_setting",
              code := 2210
            },
            {
              name := "reserved",
              code := 0
            },
            {
              name := "mcp_status",
              code := 0
            },
            {
              name := "vnav_mode",
              code := 0
            },
            {
              name := "alt_hold_mode",
              code := 0
            },
            {
              name := "approach_mode",
              code := 0
            },
            {
              name := "reserved2",
              code := 0
            },
            {
              name := "source_status",
              code := 0
            },
            {
              name := "target_altitude_source",
              code := 0
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (33,
        {
          tableValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 37),
            ("reg_char2",
            some 7),
            ("reg_char3",
            some 0),
            ("reg_char4",
            some 0),
            ("reg_char5",
            some 24),
            ("reg_char6",
            some 40),
            ("reg_char7",
            some 32),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          standardValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 37),
            ("reg_char2",
            some 7),
            ("reg_char3",
            some 0),
            ("reg_char4",
            some 0),
            ("reg_char5",
            some 24),
            ("reg_char6",
            some 40),
            ("reg_char7",
            some 32),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          oracleValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 37),
            ("reg_char2",
            some 7),
            ("reg_char3",
            some 0),
            ("reg_char4",
            some 0),
            ("reg_char5",
            some 24),
            ("reg_char6",
            some 40),
            ("reg_char7",
            some 32),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          standardLabels := [
            ("registration",
            some "#GX#"),
            ("airline",
            none)
          ],
          oracleLabels := [
            ("registration",
            some "#GX#"),
            ("airline",
            none)
          ],
          standardFloats := [
            
          ],
          oracleFloats := [
            
          ],
          standardThreat := none,
          oracleThreat := none
        }),
        (64,
        {
          tableValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 38000),
            ("fms_valid",
            some 0),
            ("selected_fms",
            none),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some 1021),
            ("reserved",
            some 0),
            ("mcp_status",
            some 0),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 0),
            ("target_altitude_source",
            some 0)
          ],
          standardValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 38000),
            ("fms_valid",
            some 0),
            ("selected_fms",
            none),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some 1021),
            ("reserved",
            some 0),
            ("mcp_status",
            some 0),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 0),
            ("target_altitude_source",
            some 0)
          ],
          oracleValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 38000),
            ("fms_valid",
            some 0),
            ("selected_fms",
            none),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some 1021),
            ("reserved",
            some 0),
            ("mcp_status",
            some 0),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 0),
            ("target_altitude_source",
            some 0)
          ],
          standardLabels := [
            ("target_altitude_source",
            some "Unknown")
          ],
          oracleLabels := [
            ("target_altitude_source",
            some "Unknown")
          ],
          standardFloats := [
            {
              key := "barometric_setting",
              value := some (Presentation.FloatExpr.add (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2210) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((1 : Rat) / 10))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 800)),
              missing := Presentation.Missing.omit
            }
          ],
          oracleFloats := [
            {
              key := "barometric_setting",
              value := some (Presentation.FloatExpr.add (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2210) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((1 : Rat) / 10))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 800)),
              missing := Presentation.Missing.omit
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `address_parity_frame` and its semantic checks. -/
theorem address_parity_full :
    Lean1090.Spec.decode address_parityBytes = address_parityExpected := by
  decide +kernel

example : Lean1090.Spec.decode address_parityBytes = address_parityExpected := address_parity_full

/-- Complete literal regression snapshot for the `all_callBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def all_callExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.allCall 0x5#3 0x484fde#24,
      parity := 0xa248f5#24
    },
    decoded := {
      crc := 0x000016#24,
      address := some 0x484fde#24,
      interrogator := some (0x1#3,
      0x6#4),
      altitude := none,
      identity := none,
      adsb := none,
      commB := [
        
      ],
      semanticADSB := none,
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `all_call_frame` and its semantic checks. -/
theorem all_call_full :
    Lean1090.Spec.decode all_callBytes = all_callExpected := by
  decide +kernel

example : Lean1090.Spec.decode all_callBytes = all_callExpected := all_call_full

/-- Complete literal regression snapshot for the `altitudeBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def altitudeExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.surveillance false {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x1718#13
      },
      parity := 0x06a983#24
    },
    decoded := {
      crc := 0x4ca7e8#24,
      address := some 0x4ca7e8#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 36000),
      identity := none,
      adsb := none,
      commB := [
        
      ],
      semanticADSB := none,
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `altitude_frame` and its semantic checks. -/
theorem altitude_full :
    Lean1090.Spec.decode altitudeBytes = altitudeExpected := by
  decide +kernel

example : Lean1090.Spec.decode altitudeBytes = altitudeExpected := altitude_full

/-- Complete literal regression snapshot for the `identityBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def identityExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.surveillance true {
        fs := 0x2#3,
        dr := 0x00#5,
        um := 0x02#6,
        code := 0x116d#13
      },
      parity := 0x492b80#24
    },
    decoded := {
      crc := 0x510af9#24,
      address := some 0x510af9#24,
      interrogator := none,
      altitude := none,
      identity := some 238,
      adsb := none,
      commB := [
        
      ],
      semanticADSB := none,
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `identity_frame` and its semantic checks. -/
theorem identity_full :
    Lean1090.Spec.decode identityBytes = identityExpected := by
  decide +kernel

example : Lean1090.Spec.decode identityBytes = identityExpected := identity_full

/-- Complete literal regression snapshot for the `gicbBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def gicbExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB false {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x0638#13
      } 0xfa81c100000000#56,
      parity := 0x81a92f#24
    },
    decoded := {
      crc := 0x484cb8#24,
      address := some 0x484cb8#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 9200),
      identity := none,
      adsb := none,
      commB := [
        (23,
        {
          kind := 23,
          fields := [
            {
              name := "bds05",
              code := 1
            },
            {
              name := "bds06",
              code := 1
            },
            {
              name := "bds07",
              code := 1
            },
            {
              name := "bds08",
              code := 1
            },
            {
              name := "bds09",
              code := 1
            },
            {
              name := "bds0a",
              code := 0
            },
            {
              name := "bds20",
              code := 1
            },
            {
              name := "bds21",
              code := 0
            },
            {
              name := "bds40",
              code := 1
            },
            {
              name := "bds41",
              code := 0
            },
            {
              name := "bds42",
              code := 0
            },
            {
              name := "bds43",
              code := 0
            },
            {
              name := "bds44",
              code := 0
            },
            {
              name := "bds45",
              code := 0
            },
            {
              name := "bds48",
              code := 0
            },
            {
              name := "bds50",
              code := 1
            },
            {
              name := "bds51",
              code := 1
            },
            {
              name := "bds52",
              code := 1
            },
            {
              name := "bds53",
              code := 0
            },
            {
              name := "bds54",
              code := 0
            },
            {
              name := "bds55",
              code := 0
            },
            {
              name := "bds56",
              code := 0
            },
            {
              name := "bds5f",
              code := 0
            },
            {
              name := "bds60",
              code := 1
            },
            {
              name := "reserved",
              code := 0
            },
            {
              name := "zero_tail",
              code := 0
            }
          ]
        }),
        (33,
        {
          kind := 33,
          fields := [
            {
              name := "ac_status",
              code := 1
            },
            {
              name := "reg_char1",
              code := 61
            },
            {
              name := "reg_char2",
              code := 16
            },
            {
              name := "reg_char3",
              code := 14
            },
            {
              name := "reg_char4",
              code := 2
            },
            {
              name := "reg_char5",
              code := 0
            },
            {
              name := "reg_char6",
              code := 0
            },
            {
              name := "reg_char7",
              code := 0
            },
            {
              name := "al_status",
              code := 0
            },
            {
              name := "airline_char1",
              code := 0
            },
            {
              name := "airline_char2",
              code := 0
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (23,
        {
          tableValues := [
            ("bds05",
            some 1),
            ("bds06",
            some 1),
            ("bds07",
            some 1),
            ("bds08",
            some 1),
            ("bds09",
            some 1),
            ("bds0a",
            some 0),
            ("bds20",
            some 1),
            ("bds21",
            some 0),
            ("bds40",
            some 1),
            ("bds41",
            some 0),
            ("bds42",
            some 0),
            ("bds43",
            some 0),
            ("bds44",
            some 0),
            ("bds45",
            some 0),
            ("bds48",
            some 0),
            ("bds50",
            some 1),
            ("bds51",
            some 1),
            ("bds52",
            some 1),
            ("bds53",
            some 0),
            ("bds54",
            some 0),
            ("bds55",
            some 0),
            ("bds56",
            some 0),
            ("bds5f",
            some 0),
            ("bds60",
            some 1),
            ("reserved",
            some 0),
            ("zero_tail",
            some 0)
          ],
          standardValues := [
            ("bds05",
            some 1),
            ("bds06",
            some 1),
            ("bds07",
            some 1),
            ("bds08",
            some 1),
            ("bds09",
            some 1),
            ("bds0a",
            some 0),
            ("bds20",
            some 1),
            ("bds21",
            some 0),
            ("bds40",
            some 1),
            ("bds41",
            some 0),
            ("bds42",
            some 0),
            ("bds43",
            some 0),
            ("bds44",
            some 0),
            ("bds45",
            some 0),
            ("bds48",
            some 0),
            ("bds50",
            some 1),
            ("bds51",
            some 1),
            ("bds52",
            some 1),
            ("bds53",
            some 0),
            ("bds54",
            some 0),
            ("bds55",
            some 0),
            ("bds56",
            some 0),
            ("bds5f",
            some 0),
            ("bds60",
            some 1),
            ("reserved",
            some 0),
            ("zero_tail",
            some 0)
          ],
          oracleValues := [
            ("bds05",
            some 1),
            ("bds06",
            some 1),
            ("bds07",
            some 1),
            ("bds08",
            some 1),
            ("bds09",
            some 1),
            ("bds0a",
            some 0),
            ("bds20",
            some 1),
            ("bds21",
            some 0),
            ("bds40",
            some 1),
            ("bds41",
            some 0),
            ("bds42",
            some 0),
            ("bds43",
            some 0),
            ("bds44",
            some 0),
            ("bds45",
            some 0),
            ("bds48",
            some 0),
            ("bds50",
            some 1),
            ("bds51",
            some 1),
            ("bds52",
            some 1),
            ("bds53",
            some 0),
            ("bds54",
            some 0),
            ("bds55",
            some 0),
            ("bds56",
            some 0),
            ("bds5f",
            some 0),
            ("bds60",
            some 1),
            ("reserved",
            some 0),
            ("zero_tail",
            some 0)
          ],
          standardLabels := [
            
          ],
          oracleLabels := [
            
          ],
          standardFloats := [
            
          ],
          oracleFloats := [
            
          ],
          standardThreat := none,
          oracleThreat := none
        }),
        (33,
        {
          tableValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 61),
            ("reg_char2",
            some 16),
            ("reg_char3",
            some 14),
            ("reg_char4",
            some 2),
            ("reg_char5",
            some 0),
            ("reg_char6",
            some 0),
            ("reg_char7",
            some 0),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          standardValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 61),
            ("reg_char2",
            some 16),
            ("reg_char3",
            some 14),
            ("reg_char4",
            some 2),
            ("reg_char5",
            some 0),
            ("reg_char6",
            some 0),
            ("reg_char7",
            some 0),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          oracleValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 61),
            ("reg_char2",
            some 16),
            ("reg_char3",
            some 14),
            ("reg_char4",
            some 2),
            ("reg_char5",
            some 0),
            ("reg_char6",
            some 0),
            ("reg_char7",
            some 0),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          standardLabels := [
            ("registration",
            some "#PNB"),
            ("airline",
            none)
          ],
          oracleLabels := [
            ("registration",
            some "#PNB"),
            ("airline",
            none)
          ],
          standardFloats := [
            
          ],
          oracleFloats := [
            
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `gicb_frame` and its semantic checks. -/
theorem gicb_full :
    Lean1090.Spec.decode gicbBytes = gicbExpected := by
  decide +kernel

example : Lean1090.Spec.decode gicbBytes = gicbExpected := gicb_full

/-- Complete literal regression snapshot for the `commb_identificationBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def commb_identificationExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB false {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x083e#13
      } 0x202cc371c31de0#56,
      parity := 0xaa1ccf#24
    },
    decoded := {
      crc := 0x484163#24,
      address := some 0x484163#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 12550),
      identity := none,
      adsb := none,
      commB := [
        (32,
        {
          kind := 32,
          fields := [
            {
              name := "bds",
              code := 32
            },
            {
              name := "char1",
              code := 11
            },
            {
              name := "char2",
              code := 12
            },
            {
              name := "char3",
              code := 13
            },
            {
              name := "char4",
              code := 49
            },
            {
              name := "char5",
              code := 48
            },
            {
              name := "char6",
              code := 49
            },
            {
              name := "char7",
              code := 55
            },
            {
              name := "char8",
              code := 32
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (32,
        {
          tableValues := [
            ("bds",
            some 32),
            ("char1",
            some 11),
            ("char2",
            some 12),
            ("char3",
            some 13),
            ("char4",
            some 49),
            ("char5",
            some 48),
            ("char6",
            some 49),
            ("char7",
            some 55),
            ("char8",
            some 32)
          ],
          standardValues := [
            ("bds",
            some 32),
            ("char1",
            some 11),
            ("char2",
            some 12),
            ("char3",
            some 13),
            ("char4",
            some 49),
            ("char5",
            some 48),
            ("char6",
            some 49),
            ("char7",
            some 55),
            ("char8",
            some 32)
          ],
          oracleValues := [
            ("bds",
            some 32),
            ("char1",
            some 11),
            ("char2",
            some 12),
            ("char3",
            some 13),
            ("char4",
            some 49),
            ("char5",
            some 48),
            ("char6",
            some 49),
            ("char7",
            some 55),
            ("char8",
            some 32)
          ],
          standardLabels := [
            ("callsign",
            some "KLM1017")
          ],
          oracleLabels := [
            ("callsign",
            some "KLM1017")
          ],
          standardFloats := [
            
          ],
          oracleFloats := [
            
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `commb_identification_frame` and its semantic checks. -/
theorem commb_identification_full :
    Lean1090.Spec.decode commb_identificationBytes = commb_identificationExpected := by
  decide +kernel

example : Lean1090.Spec.decode commb_identificationBytes = commb_identificationExpected := commb_identification_full

/-- Complete literal regression snapshot for the `selected_altitudeBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def selected_altitudeExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB true {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x1ebc#13
      } 0xaee57730a80106#56,
      parity := 0xde1344#24
    },
    decoded := {
      crc := 0x48548e#24,
      address := some 0x48548e#24,
      interrogator := none,
      altitude := none,
      identity := some 3803,
      adsb := none,
      commB := [
        (64,
        {
          kind := 64,
          fields := [
            {
              name := "mcp_valid",
              code := 1
            },
            {
              name := "selected_mcp",
              code := 1500
            },
            {
              name := "fms_valid",
              code := 1
            },
            {
              name := "selected_fms",
              code := 1500
            },
            {
              name := "qnh_valid",
              code := 1
            },
            {
              name := "barometric_setting",
              code := 2132
            },
            {
              name := "reserved",
              code := 0
            },
            {
              name := "mcp_status",
              code := 1
            },
            {
              name := "vnav_mode",
              code := 0
            },
            {
              name := "alt_hold_mode",
              code := 0
            },
            {
              name := "approach_mode",
              code := 0
            },
            {
              name := "reserved2",
              code := 0
            },
            {
              name := "source_status",
              code := 1
            },
            {
              name := "target_altitude_source",
              code := 2
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (64,
        {
          tableValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 24000),
            ("fms_valid",
            some 1),
            ("selected_fms",
            some 24000),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some ((5066 : Rat) / 5)),
            ("reserved",
            some 0),
            ("mcp_status",
            some 1),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 1),
            ("target_altitude_source",
            some 2)
          ],
          standardValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 24000),
            ("fms_valid",
            some 1),
            ("selected_fms",
            some 24000),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some ((5066 : Rat) / 5)),
            ("reserved",
            some 0),
            ("mcp_status",
            some 1),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 1),
            ("target_altitude_source",
            some 2)
          ],
          oracleValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 24000),
            ("fms_valid",
            some 1),
            ("selected_fms",
            some 24000),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some ((5066 : Rat) / 5)),
            ("reserved",
            some 0),
            ("mcp_status",
            some 1),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 1),
            ("target_altitude_source",
            some 2)
          ],
          standardLabels := [
            ("target_altitude_source",
            some "FcpMcuSelectedAltitude")
          ],
          oracleLabels := [
            ("target_altitude_source",
            some "FcpMcuSelectedAltitude")
          ],
          standardFloats := [
            {
              key := "barometric_setting",
              value := some (Presentation.FloatExpr.add (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2132) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((1 : Rat) / 10))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 800)),
              missing := Presentation.Missing.omit
            }
          ],
          oracleFloats := [
            {
              key := "barometric_setting",
              value := some (Presentation.FloatExpr.add (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2132) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((1 : Rat) / 10))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 800)),
              missing := Presentation.Missing.omit
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `selected_altitude_frame` and its semantic checks. -/
theorem selected_altitude_full :
    Lean1090.Spec.decode selected_altitudeBytes = selected_altitudeExpected := by
  decide +kernel

example : Lean1090.Spec.decode selected_altitudeBytes = selected_altitudeExpected := selected_altitude_full

/-- Complete literal regression snapshot for the `track_turnBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def track_turnExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB true {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x06ac#13
      } 0xf9363d3bbf9ce9#56,
      parity := 0x8f1e1d#24
    },
    decoded := {
      crc := 0x4008b4#24,
      address := some 0x4008b4#24,
      interrogator := none,
      altitude := none,
      identity := some 3282,
      adsb := none,
      commB := [
        (80,
        {
          kind := 80,
          fields := [
            {
              name := "roll_valid",
              code := 1
            },
            {
              name := "roll",
              code := 969
            },
            {
              name := "track_valid",
              code := 1
            },
            {
              name := "track",
              code := 798
            },
            {
              name := "groundspeed_valid",
              code := 1
            },
            {
              name := "groundspeed",
              code := 238
            },
            {
              name := "track_rate_valid",
              code := 1
            },
            {
              name := "track_rate",
              code := 1011
            },
            {
              name := "tas_valid",
              code := 1
            },
            {
              name := "TAS",
              code := 233
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (80,
        {
          tableValues := [
            ("roll_valid",
            some 1),
            ("roll",
            some ((-2475 : Rat) / 256)),
            ("track_valid",
            some 1),
            ("track",
            some ((17955 : Rat) / 128)),
            ("groundspeed_valid",
            some 1),
            ("groundspeed",
            some 476),
            ("track_rate_valid",
            some 1),
            ("track_rate",
            some ((-13 : Rat) / 32)),
            ("tas_valid",
            some 1),
            ("TAS",
            some 466)
          ],
          standardValues := [
            ("roll_valid",
            some 1),
            ("roll",
            some ((-2475 : Rat) / 256)),
            ("track_valid",
            some 1),
            ("track",
            some ((17955 : Rat) / 128)),
            ("groundspeed_valid",
            some 1),
            ("groundspeed",
            some 476),
            ("track_rate_valid",
            some 1),
            ("track_rate",
            some ((-13 : Rat) / 32)),
            ("tas_valid",
            some 1),
            ("TAS",
            some 466)
          ],
          oracleValues := [
            ("roll_valid",
            some 1),
            ("roll",
            some ((-2475 : Rat) / 256)),
            ("track_valid",
            some 1),
            ("track",
            some ((17955 : Rat) / 128)),
            ("groundspeed_valid",
            some 1),
            ("groundspeed",
            some 476),
            ("track_rate_valid",
            some 1),
            ("track_rate",
            some ((-13 : Rat) / 32)),
            ("tas_valid",
            some 1),
            ("TAS",
            some 466)
          ],
          standardLabels := [
            
          ],
          oracleLabels := [
            
          ],
          standardFloats := [
            {
              key := "roll",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-55)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 45)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            },
            {
              key := "track",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 798) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.null
            },
            {
              key := "track_rate",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-13)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 8)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            }
          ],
          oracleFloats := [
            {
              key := "roll",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-55)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 45)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            },
            {
              key := "track",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 798) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.null
            },
            {
              key := "track_rate",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-13)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 8)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `track_turn_frame` and its semantic checks. -/
theorem track_turn_full :
    Lean1090.Spec.decode track_turnBytes = track_turnExpected := by
  decide +kernel

example : Lean1090.Spec.decode track_turnBytes = track_turnExpected := track_turn_full

/-- Complete literal regression snapshot for the `heading_speedBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def heading_speedExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB true {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x04aa#13
      } 0xa74a072bfdefc1#56,
      parity := 0xd5cb4f#24
    },
    decoded := {
      crc := 0x4ca53f#24,
      address := some 0x4ca53f#24,
      interrogator := none,
      altitude := none,
      identity := some 2512,
      adsb := none,
      commB := [
        (96,
        {
          kind := 96,
          fields := [
            {
              name := "heading_valid",
              code := 1
            },
            {
              name := "heading",
              code := 628
            },
            {
              name := "ias_valid",
              code := 1
            },
            {
              name := "IAS",
              code := 259
            },
            {
              name := "mach_valid",
              code := 1
            },
            {
              name := "Mach",
              code := 175
            },
            {
              name := "barometric_rate_valid",
              code := 1
            },
            {
              name := "vrate_barometric",
              code := 957
            },
            {
              name := "inertial_rate_valid",
              code := 1
            },
            {
              name := "vrate_inertial",
              code := 961
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (96,
        {
          tableValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((7065 : Rat) / 64)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 259),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((7 : Rat) / 10)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some (-2144)),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some (-2016))
          ],
          standardValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((7065 : Rat) / 64)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 259),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((7 : Rat) / 10)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some (-2144)),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some (-2016))
          ],
          oracleValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((7065 : Rat) / 64)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 259),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((7 : Rat) / 10)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some (-2144)),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some (-2016))
          ],
          standardLabels := [
            
          ],
          oracleLabels := [
            
          ],
          standardFloats := [
            {
              key := "heading",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 628) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.omit
            },
            {
              key := "Mach",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 175) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((256 : Rat) / 125))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512)),
              missing := Presentation.Missing.omit
            }
          ],
          oracleFloats := [
            {
              key := "heading",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 628) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.omit
            },
            {
              key := "Mach",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 175) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((256 : Rat) / 125))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512)),
              missing := Presentation.Missing.omit
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `heading_speed_frame` and its semantic checks. -/
theorem heading_speed_full :
    Lean1090.Spec.decode heading_speedBytes = heading_speedExpected := by
  decide +kernel

example : Lean1090.Spec.decode heading_speedBytes = heading_speedExpected := heading_speed_full

/-- Complete literal regression snapshot for the `meteo_routineBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def meteo_routineExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB false {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x1692#13
      } 0x185bd5cf400000#56,
      parity := 0xdfc696#24
    },
    decoded := {
      crc := 0x3c4dd7#24,
      address := some 0x3c4dd7#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 35050),
      identity := none,
      adsb := none,
      commB := [
        (68,
        {
          kind := 68,
          fields := [
            {
              name := "figure_of_merit",
              code := 1
            },
            {
              name := "wind_valid",
              code := 1
            },
            {
              name := "wind_speed",
              code := 22
            },
            {
              name := "wind_direction",
              code := 490
            },
            {
              name := "temperature",
              code := 1853
            },
            {
              name := "pressure_valid",
              code := 0
            },
            {
              name := "pressure",
              code := 0
            },
            {
              name := "turbulence_valid",
              code := 0
            },
            {
              name := "turbulence",
              code := 0
            },
            {
              name := "humidity_valid",
              code := 0
            },
            {
              name := "humidity",
              code := 0
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (68,
        {
          tableValues := [
            ("figure_of_merit",
            some 1),
            ("wind_valid",
            some 1),
            ("wind_speed",
            some 22),
            ("wind_direction",
            some ((11025 : Rat) / 32)),
            ("temperature",
            some ((-195 : Rat) / 4)),
            ("pressure_valid",
            some 0),
            ("pressure",
            none),
            ("turbulence_valid",
            some 0),
            ("turbulence",
            none),
            ("humidity_valid",
            some 0),
            ("humidity",
            none)
          ],
          standardValues := [
            ("figure_of_merit",
            some 1),
            ("wind_valid",
            some 1),
            ("wind_speed",
            some 22),
            ("wind_direction",
            some ((11025 : Rat) / 32)),
            ("temperature",
            some ((-195 : Rat) / 4)),
            ("pressure_valid",
            some 0),
            ("pressure",
            none),
            ("turbulence_valid",
            some 0),
            ("turbulence",
            none),
            ("humidity_valid",
            some 0),
            ("humidity",
            none)
          ],
          oracleValues := [
            ("figure_of_merit",
            some 1),
            ("wind_valid",
            some 1),
            ("wind_speed",
            some 22),
            ("wind_direction",
            some ((11025 : Rat) / 32)),
            ("temperature",
            some ((-195 : Rat) / 4)),
            ("pressure_valid",
            some 0),
            ("pressure",
            none),
            ("turbulence_valid",
            some 0),
            ("turbulence",
            none),
            ("humidity_valid",
            some 0),
            ("humidity",
            none)
          ],
          standardLabels := [
            ("figure_of_merit",
            some "INS"),
            ("turbulence",
            none)
          ],
          oracleLabels := [
            ("figure_of_merit",
            some "INS"),
            ("turbulence",
            none)
          ],
          standardFloats := [
            {
              key := "wind_direction",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 490) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 180)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            },
            {
              key := "temperature",
              value := some (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((-195 : Rat) / 4)),
              missing := Presentation.Missing.null
            },
            {
              key := "humidity",
              value := none,
              missing := Presentation.Missing.null
            }
          ],
          oracleFloats := [
            {
              key := "wind_direction",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 490) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 180)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            },
            {
              key := "temperature",
              value := some (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((-195 : Rat) / 4)),
              missing := Presentation.Missing.null
            },
            {
              key := "humidity",
              value := none,
              missing := Presentation.Missing.null
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `meteo_routine_frame` and its semantic checks. -/
theorem meteo_routine_full :
    Lean1090.Spec.decode meteo_routineBytes = meteo_routineExpected := by
  decide +kernel

example : Lean1090.Spec.decode meteo_routineBytes = meteo_routineExpected := meteo_routine_full

/-- Complete literal regression snapshot for the `meteo_hazardBytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def meteo_hazardExpected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB false {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x1692#13
      } 0x0001cf40000000#56,
      parity := 0x8bd87b#24
    },
    decoded := {
      crc := 0x3c4dd7#24,
      address := some 0x3c4dd7#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 35050),
      identity := none,
      adsb := none,
      commB := [
        (69,
        {
          kind := 69,
          fields := [
            {
              name := "turbulence_valid",
              code := 0
            },
            {
              name := "turbulence",
              code := 0
            },
            {
              name := "wind_shear_valid",
              code := 0
            },
            {
              name := "wind_shear",
              code := 0
            },
            {
              name := "microburst_valid",
              code := 0
            },
            {
              name := "microburst",
              code := 0
            },
            {
              name := "icing_valid",
              code := 0
            },
            {
              name := "icing",
              code := 0
            },
            {
              name := "wake_vortex_valid",
              code := 0
            },
            {
              name := "wake_vortex",
              code := 0
            },
            {
              name := "temperature_valid",
              code := 1
            },
            {
              name := "static_temperature",
              code := 829
            },
            {
              name := "pressure_valid",
              code := 0
            },
            {
              name := "static_pressure",
              code := 0
            },
            {
              name := "height_valid",
              code := 0
            },
            {
              name := "radio_height",
              code := 0
            },
            {
              name := "reserved",
              code := 0
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (69,
        {
          tableValues := [
            ("turbulence_valid",
            some 0),
            ("turbulence",
            none),
            ("wind_shear_valid",
            some 0),
            ("wind_shear",
            none),
            ("microburst_valid",
            some 0),
            ("microburst",
            none),
            ("icing_valid",
            some 0),
            ("icing",
            none),
            ("wake_vortex_valid",
            some 0),
            ("wake_vortex",
            none),
            ("temperature_valid",
            some 1),
            ("static_temperature",
            some ((-195 : Rat) / 4)),
            ("pressure_valid",
            some 0),
            ("static_pressure",
            none),
            ("height_valid",
            some 0),
            ("radio_height",
            none),
            ("reserved",
            some 0)
          ],
          standardValues := [
            ("turbulence_valid",
            some 0),
            ("turbulence",
            none),
            ("wind_shear_valid",
            some 0),
            ("wind_shear",
            none),
            ("microburst_valid",
            some 0),
            ("microburst",
            none),
            ("icing_valid",
            some 0),
            ("icing",
            none),
            ("wake_vortex_valid",
            some 0),
            ("wake_vortex",
            none),
            ("temperature_valid",
            some 1),
            ("static_temperature",
            some ((-195 : Rat) / 4)),
            ("pressure_valid",
            some 0),
            ("static_pressure",
            none),
            ("height_valid",
            some 0),
            ("radio_height",
            none),
            ("reserved",
            some 0)
          ],
          oracleValues := [
            ("turbulence_valid",
            some 0),
            ("turbulence",
            none),
            ("wind_shear_valid",
            some 0),
            ("wind_shear",
            none),
            ("microburst_valid",
            some 0),
            ("microburst",
            none),
            ("icing_valid",
            some 0),
            ("icing",
            none),
            ("wake_vortex_valid",
            some 0),
            ("wake_vortex",
            none),
            ("temperature_valid",
            some 1),
            ("static_temperature",
            some ((-195 : Rat) / 4)),
            ("pressure_valid",
            some 0),
            ("static_pressure",
            none),
            ("height_valid",
            some 0),
            ("radio_height",
            none),
            ("reserved",
            some 0)
          ],
          standardLabels := [
            ("turbulence",
            none),
            ("wind_shear",
            none),
            ("microburst",
            none),
            ("icing",
            none),
            ("wake_vortex",
            none)
          ],
          oracleLabels := [
            ("turbulence",
            none),
            ("wind_shear",
            none),
            ("microburst",
            none),
            ("icing",
            none),
            ("wake_vortex",
            none)
          ],
          standardFloats := [
            {
              key := "static_temperature",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-195)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 1)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 4)),
              missing := Presentation.Missing.null
            }
          ],
          oracleFloats := [
            {
              key := "static_temperature",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-195)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 1)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 4)),
              missing := Presentation.Missing.null
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `meteo_hazard_frame` and its semantic checks. -/
theorem meteo_hazard_full :
    Lean1090.Spec.decode meteo_hazardBytes = meteo_hazardExpected := by
  decide +kernel

example : Lean1090.Spec.decode meteo_hazardBytes = meteo_hazardExpected := meteo_hazard_full

/-- Complete literal regression snapshot for the `inference_df20Bytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def inference_df20Expected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB false {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x1838#13
      } 0xe519f331602401#56,
      parity := 0x42d7fa#24
    },
    decoded := {
      crc := 0x3c674d#24,
      address := some 0x3c674d#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 38000),
      identity := none,
      adsb := none,
      commB := [
        (96,
        {
          kind := 96,
          fields := [
            {
              name := "heading_valid",
              code := 1
            },
            {
              name := "heading",
              code := 1617
            },
            {
              name := "ias_valid",
              code := 1
            },
            {
              name := "IAS",
              code := 249
            },
            {
              name := "mach_valid",
              code := 1
            },
            {
              name := "Mach",
              code := 197
            },
            {
              name := "barometric_rate_valid",
              code := 1
            },
            {
              name := "vrate_barometric",
              code := 4
            },
            {
              name := "inertial_rate_valid",
              code := 1
            },
            {
              name := "vrate_inertial",
              code := 1
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (96,
        {
          tableValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((-19395 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 249),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((197 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 128),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 32)
          ],
          standardValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((-19395 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 249),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((197 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 128),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 32)
          ],
          oracleValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((72765 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 249),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((197 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 128),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 32)
          ],
          standardLabels := [
            
          ],
          oracleLabels := [
            
          ],
          standardFloats := [
            {
              key := "heading",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-431)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.omit
            },
            {
              key := "Mach",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 197) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((256 : Rat) / 125))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512)),
              missing := Presentation.Missing.omit
            }
          ],
          oracleFloats := [
            {
              key := "heading",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-431)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.omit
            },
            {
              key := "Mach",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 197) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((256 : Rat) / 125))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512)),
              missing := Presentation.Missing.omit
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `inference_df20_frame` and its semantic checks. -/
theorem inference_df20_full :
    Lean1090.Spec.decode inference_df20Bytes = inference_df20Expected := by
  decide +kernel

example : Lean1090.Spec.decode inference_df20Bytes = inference_df20Expected := inference_df20_full

/-- Complete literal regression snapshot for the `inference_df21Bytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def inference_df21Expected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB true {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x1ebc#13
      } 0xfffb23286004a7#56,
      parity := 0x3f6a5b#24
    },
    decoded := {
      crc := 0x48548e#24,
      address := some 0x48548e#24,
      interrogator := none,
      altitude := none,
      identity := some 3803,
      adsb := none,
      commB := [
        (80,
        {
          kind := 80,
          fields := [
            {
              name := "roll_valid",
              code := 1
            },
            {
              name := "roll",
              code := 1023
            },
            {
              name := "track_valid",
              code := 1
            },
            {
              name := "track",
              code := 1425
            },
            {
              name := "groundspeed_valid",
              code := 1
            },
            {
              name := "groundspeed",
              code := 161
            },
            {
              name := "track_rate_valid",
              code := 1
            },
            {
              name := "track_rate",
              code := 0
            },
            {
              name := "tas_valid",
              code := 1
            },
            {
              name := "TAS",
              code := 167
            }
          ]
        }),
        (96,
        {
          kind := 96,
          fields := [
            {
              name := "heading_valid",
              code := 1
            },
            {
              name := "heading",
              code := 2047
            },
            {
              name := "ias_valid",
              code := 1
            },
            {
              name := "IAS",
              code := 401
            },
            {
              name := "mach_valid",
              code := 1
            },
            {
              name := "Mach",
              code := 161
            },
            {
              name := "barometric_rate_valid",
              code := 1
            },
            {
              name := "vrate_barometric",
              code := 0
            },
            {
              name := "inertial_rate_valid",
              code := 1
            },
            {
              name := "vrate_inertial",
              code := 167
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (80,
        {
          tableValues := [
            ("roll_valid",
            some 1),
            ("roll",
            some ((-45 : Rat) / 256)),
            ("track_valid",
            some 1),
            ("track",
            some ((-28035 : Rat) / 256)),
            ("groundspeed_valid",
            some 1),
            ("groundspeed",
            some 322),
            ("track_rate_valid",
            some 1),
            ("track_rate",
            some 0),
            ("tas_valid",
            some 1),
            ("TAS",
            some 334)
          ],
          standardValues := [
            ("roll_valid",
            some 1),
            ("roll",
            some ((-45 : Rat) / 256)),
            ("track_valid",
            some 1),
            ("track",
            some ((-28035 : Rat) / 256)),
            ("groundspeed_valid",
            some 1),
            ("groundspeed",
            some 322),
            ("track_rate_valid",
            some 1),
            ("track_rate",
            some 0),
            ("tas_valid",
            some 1),
            ("TAS",
            some 334)
          ],
          oracleValues := [
            ("roll_valid",
            some 1),
            ("roll",
            some ((-45 : Rat) / 256)),
            ("track_valid",
            some 1),
            ("track",
            some ((64125 : Rat) / 256)),
            ("groundspeed_valid",
            some 1),
            ("groundspeed",
            some 322),
            ("track_rate_valid",
            some 1),
            ("track_rate",
            some 0),
            ("tas_valid",
            some 1),
            ("TAS",
            some 334)
          ],
          standardLabels := [
            
          ],
          oracleLabels := [
            
          ],
          standardFloats := [
            {
              key := "roll",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-1)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 45)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            },
            {
              key := "track",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-623)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.null
            },
            {
              key := "track_rate",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 0) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 8)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            }
          ],
          oracleFloats := [
            {
              key := "roll",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-1)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 45)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            },
            {
              key := "track",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-623)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.null
            },
            {
              key := "track_rate",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 0) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 8)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 256)),
              missing := Presentation.Missing.null
            }
          ],
          standardThreat := none,
          oracleThreat := none
        }),
        (96,
        {
          tableValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((-45 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 401),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((161 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 0),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 5344)
          ],
          standardValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((-45 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 401),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((161 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 0),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 5344)
          ],
          oracleValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((92115 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 401),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((161 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 0),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 5344)
          ],
          standardLabels := [
            
          ],
          oracleLabels := [
            
          ],
          standardFloats := [
            {
              key := "heading",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-1)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.omit
            },
            {
              key := "Mach",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 161) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((256 : Rat) / 125))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512)),
              missing := Presentation.Missing.omit
            }
          ],
          oracleFloats := [
            {
              key := "heading",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-1)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.omit
            },
            {
              key := "Mach",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 161) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((256 : Rat) / 125))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512)),
              missing := Presentation.Missing.omit
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `inference_df21_frame` and its semantic checks. -/
theorem inference_df21_full :
    Lean1090.Spec.decode inference_df21Bytes = inference_df21Expected := by
  decide +kernel

example : Lean1090.Spec.decode inference_df21Bytes = inference_df21Expected := inference_df21_full

/-- Complete literal regression snapshot for the `raw_only_1Bytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def raw_only_1Expected : Option Message :=
  some {
    fields := {
      body := FrameBody.allCall 0x5#3 0x407435#24,
      parity := 0x8ad00c#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x407435#24,
      interrogator := some (0x0#3,
      0x0#4),
      altitude := none,
      identity := none,
      adsb := none,
      commB := [
        
      ],
      semanticADSB := none,
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `raw_only_1_frame` and its semantic checks. -/
theorem raw_only_1_full :
    Lean1090.Spec.decode raw_only_1Bytes = raw_only_1Expected := by
  decide +kernel

example : Lean1090.Spec.decode raw_only_1Bytes = raw_only_1Expected := raw_only_1_full

/-- Complete literal regression snapshot for the `raw_only_2Bytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def raw_only_2Expected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0x407435#24 0x990dbd01900484#56,
      parity := 0xf66c3c#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x407435#24,
      interrogator := none,
      altitude := none,
      identity := none,
      adsb := some {
        kind := 1224,
        fields := [
          {
            name := "tc",
            code := 19
          },
          {
            name := "subtype",
            code := 1
          },
          {
            name := "intent_change",
            code := 0
          },
          {
            name := "ifr_capability",
            code := 0
          },
          {
            name := "NACv",
            code := 1
          },
          {
            name := "ew_sign",
            code := 1
          },
          {
            name := "ew_velocity",
            code := 445
          },
          {
            name := "ns_sign",
            code := 0
          },
          {
            name := "ns_velocity",
            code := 12
          },
          {
            name := "vrate_source",
            code := 1
          },
          {
            name := "vrate_sign",
            code := 0
          },
          {
            name := "vertical_rate_code",
            code := 1
          },
          {
            name := "reserved",
            code := 0
          },
          {
            name := "gnss_sign",
            code := 1
          },
          {
            name := "geo_minus_baro_code",
            code := 4
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 19),
          ("subtype",
          some 1),
          ("intent_change",
          some 0),
          ("ifr_capability",
          some 0),
          ("NACv",
          some 1),
          ("ew_sign",
          some 1),
          ("ew_velocity",
          some 445),
          ("ns_sign",
          some 0),
          ("ns_velocity",
          some 12),
          ("vrate_source",
          some 1),
          ("vrate_sign",
          some 0),
          ("vertical_rate_code",
          some 1),
          ("reserved",
          some 0),
          ("gnss_sign",
          some 1),
          ("geo_minus_baro_code",
          some 4)
        ],
        standardValues := [
          ("east_velocity",
          some (-444)),
          ("north_velocity",
          some 11),
          ("vertical_rate",
          some 0),
          ("geo_minus_baro",
          some (-75)),
          ("airspeed",
          none)
        ],
        oracleValues := [
          ("east_velocity",
          some (-444)),
          ("north_velocity",
          some 11),
          ("vertical_rate",
          some 0),
          ("geo_minus_baro",
          some (-75)),
          ("airspeed",
          none)
        ],
        standardLabels := [
          ("vrate_src",
          some "barometric"),
          ("airspeed_type",
          none)
        ],
        oracleLabels := [
          ("vrate_src",
          some "GNSS"),
          ("airspeed_type",
          none)
        ],
        standardFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.hypot64 (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-444))) (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 11))),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.atan2_64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-444)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 11)) (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((884279719003555 : Rat) / 281474976710656)))))),
            missing := Presentation.Missing.null
          }
        ],
        oracleFloats := [
          {
            key := "groundspeed",
            value := some (Presentation.FloatExpr.hypot64 (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-444))) (Presentation.FloatExpr.abs64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 11))),
            missing := Presentation.Missing.null
          },
          {
            key := "track",
            value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.atan2_64 (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-444)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 11)) (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 360) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((884279719003555 : Rat) / 281474976710656)))))),
            missing := Presentation.Missing.null
          }
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `raw_only_2_frame` and its semantic checks. -/
theorem raw_only_2_full :
    Lean1090.Spec.decode raw_only_2Bytes = raw_only_2Expected := by
  decide +kernel

example : Lean1090.Spec.decode raw_only_2Bytes = raw_only_2Expected := raw_only_2_full

/-- Complete literal regression snapshot for the `raw_only_3Bytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def raw_only_3Expected : Option Message :=
  some {
    fields := {
      body := FrameBody.extended false 0x5#3 0x407435#24 0x58af828cd326fe#56,
      parity := 0x0c2fe9#24
    },
    decoded := {
      crc := 0x000000#24,
      address := some 0x407435#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 34000),
      identity := none,
      adsb := some {
        kind := 704,
        fields := [
          {
            name := "tc",
            code := 11
          },
          {
            name := "ss",
            code := 0
          },
          {
            name := "saf_or_nicb",
            code := 0
          },
          {
            name := "altitude_code",
            code := 2808
          },
          {
            name := "time_sync",
            code := 0
          },
          {
            name := "parity",
            code := 0
          },
          {
            name := "lat_cpr",
            code := 83561
          },
          {
            name := "lon_cpr",
            code := 75518
          }
        ]
      },
      commB := [
        
      ],
      semanticADSB := some {
        tableValues := [
          ("tc",
          some 11),
          ("ss",
          some 0),
          ("saf_or_nicb",
          some 0),
          ("altitude_code",
          some 2808),
          ("time_sync",
          some 0),
          ("parity",
          some 0),
          ("lat_cpr",
          some 83561),
          ("lon_cpr",
          some 75518)
        ],
        standardValues := [
          ("NUCp",
          some 7),
          ("NICb",
          some 0),
          ("altitude_feet",
          some 34000),
          ("height_metres",
          none)
        ],
        oracleValues := [
          ("NUCp",
          some 7),
          ("NICb",
          some 0),
          ("altitude_feet",
          some 34000)
        ],
        standardLabels := [
          ("source",
          some "barometric")
        ],
        oracleLabels := [
          ("source",
          some "barometric")
        ],
        standardFloats := [
          
        ],
        oracleFloats := [
          
        ],
        standardThreat := none,
        oracleThreat := none
      },
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `raw_only_3_frame` and its semantic checks. -/
theorem raw_only_3_full :
    Lean1090.Spec.decode raw_only_3Bytes = raw_only_3Expected := by
  decide +kernel

example : Lean1090.Spec.decode raw_only_3Bytes = raw_only_3Expected := raw_only_3_full

/-- Complete literal regression snapshot for the `raw_only_4Bytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def raw_only_4Expected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB true {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x11b1#13
      } 0xe0da112fe01400#56,
      parity := 0x60939f#24
    },
    decoded := {
      crc := 0x407435#24,
      address := some 0x407435#24,
      interrogator := none,
      altitude := none,
      identity := some 2157,
      adsb := none,
      commB := [
        (96,
        {
          kind := 96,
          fields := [
            {
              name := "heading_valid",
              code := 1
            },
            {
              name := "heading",
              code := 1549
            },
            {
              name := "ias_valid",
              code := 1
            },
            {
              name := "IAS",
              code := 264
            },
            {
              name := "mach_valid",
              code := 1
            },
            {
              name := "Mach",
              code := 191
            },
            {
              name := "barometric_rate_valid",
              code := 1
            },
            {
              name := "vrate_barometric",
              code := 2
            },
            {
              name := "inertial_rate_valid",
              code := 1
            },
            {
              name := "vrate_inertial",
              code := 0
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (96,
        {
          tableValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((-22455 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 264),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((191 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 64),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 0)
          ],
          standardValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((-22455 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 264),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((191 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 64),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 0)
          ],
          oracleValues := [
            ("heading_valid",
            some 1),
            ("heading",
            some ((69705 : Rat) / 256)),
            ("ias_valid",
            some 1),
            ("IAS",
            some 264),
            ("mach_valid",
            some 1),
            ("Mach",
            some ((191 : Rat) / 250)),
            ("barometric_rate_valid",
            some 1),
            ("vrate_barometric",
            some 64),
            ("inertial_rate_valid",
            some 1),
            ("vrate_inertial",
            some 0)
          ],
          standardLabels := [
            
          ],
          oracleLabels := [
            
          ],
          standardFloats := [
            {
              key := "heading",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-499)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.omit
            },
            {
              key := "Mach",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 191) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((256 : Rat) / 125))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512)),
              missing := Presentation.Missing.omit
            }
          ],
          oracleFloats := [
            {
              key := "heading",
              value := some (Presentation.FloatExpr.addIfNegative64 (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) (-499)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 90)) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512))),
              missing := Presentation.Missing.omit
            },
            {
              key := "Mach",
              value := some (Presentation.FloatExpr.div (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 191) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((256 : Rat) / 125))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 512)),
              missing := Presentation.Missing.omit
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `raw_only_4_frame` and its semantic checks. -/
theorem raw_only_4_full :
    Lean1090.Spec.decode raw_only_4Bytes = raw_only_4Expected := by
  decide +kernel

example : Lean1090.Spec.decode raw_only_4Bytes = raw_only_4Expected := raw_only_4_full

/-- Complete literal regression snapshot for the `raw_only_5Bytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def raw_only_5Expected : Option Message :=
  some {
    fields := {
      body := FrameBody.commB false {
        fs := 0x0#3,
        dr := 0x00#5,
        um := 0x00#6,
        code := 0x15b8#13
      } 0xc2680030a80000#56,
      parity := 0x318667#24
    },
    decoded := {
      crc := 0x407435#24,
      address := some 0x407435#24,
      interrogator := none,
      altitude := some (Altitude.Value.feet 34000),
      identity := none,
      adsb := none,
      commB := [
        (33,
        {
          kind := 33,
          fields := [
            {
              name := "ac_status",
              code := 1
            },
            {
              name := "reg_char1",
              code := 33
            },
            {
              name := "reg_char2",
              code := 13
            },
            {
              name := "reg_char3",
              code := 0
            },
            {
              name := "reg_char4",
              code := 0
            },
            {
              name := "reg_char5",
              code := 24
            },
            {
              name := "reg_char6",
              code := 21
            },
            {
              name := "reg_char7",
              code := 0
            },
            {
              name := "al_status",
              code := 0
            },
            {
              name := "airline_char1",
              code := 0
            },
            {
              name := "airline_char2",
              code := 0
            }
          ]
        }),
        (64,
        {
          kind := 64,
          fields := [
            {
              name := "mcp_valid",
              code := 1
            },
            {
              name := "selected_mcp",
              code := 2125
            },
            {
              name := "fms_valid",
              code := 0
            },
            {
              name := "selected_fms",
              code := 0
            },
            {
              name := "qnh_valid",
              code := 1
            },
            {
              name := "barometric_setting",
              code := 2132
            },
            {
              name := "reserved",
              code := 0
            },
            {
              name := "mcp_status",
              code := 0
            },
            {
              name := "vnav_mode",
              code := 0
            },
            {
              name := "alt_hold_mode",
              code := 0
            },
            {
              name := "approach_mode",
              code := 0
            },
            {
              name := "reserved2",
              code := 0
            },
            {
              name := "source_status",
              code := 0
            },
            {
              name := "target_altitude_source",
              code := 0
            }
          ]
        })
      ],
      semanticADSB := none,
      semanticCommB := [
        (33,
        {
          tableValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 33),
            ("reg_char2",
            some 13),
            ("reg_char3",
            some 0),
            ("reg_char4",
            some 0),
            ("reg_char5",
            some 24),
            ("reg_char6",
            some 21),
            ("reg_char7",
            some 0),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          standardValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 33),
            ("reg_char2",
            some 13),
            ("reg_char3",
            some 0),
            ("reg_char4",
            some 0),
            ("reg_char5",
            some 24),
            ("reg_char6",
            some 21),
            ("reg_char7",
            some 0),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          oracleValues := [
            ("ac_status",
            some 1),
            ("reg_char1",
            some 33),
            ("reg_char2",
            some 13),
            ("reg_char3",
            some 0),
            ("reg_char4",
            some 0),
            ("reg_char5",
            some 24),
            ("reg_char6",
            some 21),
            ("reg_char7",
            some 0),
            ("al_status",
            some 0),
            ("airline_char1",
            some 0),
            ("airline_char2",
            some 0)
          ],
          standardLabels := [
            ("registration",
            some "#MXU"),
            ("airline",
            none)
          ],
          oracleLabels := [
            ("registration",
            some "#MXU"),
            ("airline",
            none)
          ],
          standardFloats := [
            
          ],
          oracleFloats := [
            
          ],
          standardThreat := none,
          oracleThreat := none
        }),
        (64,
        {
          tableValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 34000),
            ("fms_valid",
            some 0),
            ("selected_fms",
            none),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some ((5066 : Rat) / 5)),
            ("reserved",
            some 0),
            ("mcp_status",
            some 0),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 0),
            ("target_altitude_source",
            some 0)
          ],
          standardValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 34000),
            ("fms_valid",
            some 0),
            ("selected_fms",
            none),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some ((5066 : Rat) / 5)),
            ("reserved",
            some 0),
            ("mcp_status",
            some 0),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 0),
            ("target_altitude_source",
            some 0)
          ],
          oracleValues := [
            ("mcp_valid",
            some 1),
            ("selected_mcp",
            some 34000),
            ("fms_valid",
            some 0),
            ("selected_fms",
            none),
            ("qnh_valid",
            some 1),
            ("barometric_setting",
            some ((5066 : Rat) / 5)),
            ("reserved",
            some 0),
            ("mcp_status",
            some 0),
            ("vnav_mode",
            some 0),
            ("alt_hold_mode",
            some 0),
            ("approach_mode",
            some 0),
            ("reserved2",
            some 0),
            ("source_status",
            some 0),
            ("target_altitude_source",
            some 0)
          ],
          standardLabels := [
            ("target_altitude_source",
            some "Unknown")
          ],
          oracleLabels := [
            ("target_altitude_source",
            some "Unknown")
          ],
          standardFloats := [
            {
              key := "barometric_setting",
              value := some (Presentation.FloatExpr.add (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2132) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((1 : Rat) / 10))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 800)),
              missing := Presentation.Missing.omit
            }
          ],
          oracleFloats := [
            {
              key := "barometric_setting",
              value := some (Presentation.FloatExpr.add (Presentation.Precision.binary64) (Presentation.FloatExpr.mul (Presentation.Precision.binary64) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 2132) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) ((1 : Rat) / 10))) (Presentation.FloatExpr.literal (Presentation.Precision.binary64) 800)),
              missing := Presentation.Missing.omit
            }
          ],
          standardThreat := none,
          oracleThreat := none
        })
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `raw_only_5_frame` and its semantic checks. -/
theorem raw_only_5_full :
    Lean1090.Spec.decode raw_only_5Bytes = raw_only_5Expected := by
  decide +kernel

example : Lean1090.Spec.decode raw_only_5Bytes = raw_only_5Expected := raw_only_5_full

/-- Complete literal regression snapshot for the `raw_only_6Bytes` source fixture.
Only the separately checked StandardExamples quantities are claimed published. -/
def raw_only_6Expected : Option Message :=
  some {
    fields := {
      body := FrameBody.allCall 0x5#3 0x407435#24,
      parity := 0x8ad030#24
    },
    decoded := {
      crc := 0x00003c#24,
      address := some 0x407435#24,
      interrogator := some (0x3#3,
      0xc#4),
      altitude := none,
      identity := none,
      adsb := none,
      commB := [
        
      ],
      semanticADSB := none,
      semanticCommB := [
        
      ]
    }
  }

/-- Kernel-check the complete result, including all fields beyond the source
excerpt. Independent source validation is `raw_only_6_frame` and its semantic checks. -/
theorem raw_only_6_full :
    Lean1090.Spec.decode raw_only_6Bytes = raw_only_6Expected := by
  decide +kernel

example : Lean1090.Spec.decode raw_only_6Bytes = raw_only_6Expected := raw_only_6_full

/-- Sun second edition (2021), §10.2 p.92: the complete result for its corrupt
DF17 message is rejection, independently stated by the source CRC example. -/
theorem crc_bad_full :
    Lean1090.Spec.decode [0x8d,0x4c,0xa2,0x51,0x20,0x49,0x94,0xb1,0xc3,0x6e,0x60,0xa5,0x34,0x3d] = none := by
  decide +kernel

example : Lean1090.Spec.decode
    [0x8d,0x4c,0xa2,0x51,0x20,0x49,0x94,0xb1,0xc3,0x6e,0x60,0xa5,0x34,0x3d] = none := crc_bad_full

end Lean1090.Spec.StandardFullExamples
