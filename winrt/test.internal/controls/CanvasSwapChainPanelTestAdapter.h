// Copyright (c) Microsoft Corporation. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may
// not use these files except in compliance with the License. You may obtain
// a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.

#pragma once

#include "..\StubSwapChainPanel.h"

class CanvasSwapChainPanelTestAdapter : public ICanvasSwapChainPanelAdapter
{
public:
    ComPtr<StubSwapChainPanel> m_stubSwapChainPanel;

    CanvasSwapChainPanelTestAdapter()
        : m_stubSwapChainPanel(Make<StubSwapChainPanel>())
    {
    }

    CanvasSwapChainPanelTestAdapter(ComPtr<StubSwapChainPanel> const& swapChainPanel)
        : m_stubSwapChainPanel(swapChainPanel)
    {
    }

    virtual std::pair<ComPtr<IInspectable>, ComPtr<ISwapChainPanel>> CreateSwapChainPanel(IInspectable* canvasSwapChain) override
    {
        ComPtr<IInspectable> inspectableControl;
        ThrowIfFailed(m_stubSwapChainPanel.As(&inspectableControl));

        return std::pair<ComPtr<IInspectable>, ComPtr<ISwapChainPanel>>(inspectableControl, m_stubSwapChainPanel);
    }
};