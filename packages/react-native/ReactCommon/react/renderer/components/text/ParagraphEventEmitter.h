/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <react/renderer/components/view/ViewEventEmitter.h>
#include <react/renderer/textlayoutmanager/TextMeasureCache.h>

namespace facebook {
namespace react {

class ParagraphEventEmitter : public ViewEventEmitter {
 public:
  using ViewEventEmitter::ViewEventEmitter;

  void onTextLayout(LinesMeasurements const &linesMeasurements, RegionsMeasurements const &regionsMeasurements) const;

 private:
  mutable std::mutex linesMeasurementsMutex_;
  mutable LinesMeasurements linesMeasurementsMetrics_;
  mutable RegionsMeasurements regionsMeasurementsMetrics_;
};

} // namespace react
} // namespace facebook
